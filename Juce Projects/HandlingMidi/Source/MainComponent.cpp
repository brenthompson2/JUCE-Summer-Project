/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent,
                                private ComboBox::Listener,
                                private MidiInputCallback,
                                private MidiKeyboardStateListener
{
public:
    //==============================================================================
    MainContentComponent()
    :   lastInputIndex (0),
        isAddingFromMidiInput (false),
        keyboardComponent (keyboardState, MidiKeyboardComponent::horizontalKeyboard),
        startTime (Time::getMillisecondCounterHiRes() * 0.001)
    {
        setSize (800, 600);
        setAudioChannels (2, 2);

        addAndMakeVisible (midiInputListLabel);
        midiInputListLabel.setText ("Midi Input", dontSendNotification);
        midiInputListLabel.attachToComponent (&midiInputList, true);

        addAndMakeVisible (midiInputList);
        midiInputList.setTextWhenNoChoicesAvailable ("No MIDI Inputs Enabled");
        const StringArray midiInputs (MidiInput::getDevices());
        midiInputList.addItemList (midiInputs, 1);
        midiInputList.addListener (this);

        // Use first enabled device as default
        for (int i = 0; i < midiInputs.size(); i++){
            if (deviceManager.isMidiInputEnabled (midiInputs[i])){
                setMidiInput(i);
                break;
            }
        }

        // If no midi devices enabled, use the first one
        if (midiInputList.getSelectedId() == 0)
            setMidiInput(0);

        addAndMakeVisible (keyboardComponent);
        keyboardState.addListener(this);

    }

    ~MainContentComponent()
    {
        keyboardState.removeListener (this);
        deviceManager.removeMidiInputCallback (MidiInput::getDevices()[midiInputList.getSelectedItemIndex()], this);
        midiInputList.removeListener (this);
        shutdownAudio();
    }

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        bufferToFill.clearActiveBufferRegion();
    }

    void releaseResources() override
    {
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    }

    void resized() override
    {
        Rectangle<int> area (getLocalBounds());
        midiInputList.setBounds (area.removeFromTop(36).removeFromRight (getWidth() - 150).reduced(8));
        keyboardComponent.setBounds (area.removeFromTop(80).reduced(8));
        midiMessagesBox.setBounds (area.reduced(8));
    }




private:
    //==============================================================================
    // Private member variables
    AudioDeviceManager deviceManager;
    ComboBox midiInputList;
    Label midiInputListLabel;
    int lastInputIndex;
    bool isAddingFromMidiInput;

    MidiKeyboardState keyboardState;
    MidiKeyboardComponent keyboardComponent;

    TextEditor midiMessagesBox;
    double startTime;

    //==============================================================================
    void setMidiInput(int index){
        const StringArray list (MidiInput::getDevices());

        deviceManager.removeMidiInputCallback (list[lastInputIndex], this);

        const String newInput (list[index]);

        if (! deviceManager.isMidiInputEnabled(newInput)){
            deviceManager.setMidiInputEnabled(newInput, true);
        }

        deviceManager.addMidiInputCallback(newInput, this);
        midiInputList.setSelectedId (index + 1, dontSendNotification);

        lastInputIndex = index;
    }

    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override{
        const ScopedValueSetter<bool> scopedInputFlag (isAddingFromMidiInput, true);
        keyboardState.processNextMidiEvent (message);
        // postMessageToList(message, source->getName());
    }

    void handleNoteOn (MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override{
        if (! isAddingFromMidiInput){
            MidiMessage m (MidiMessage::noteOn (midiChannel, midiNoteNumber, velocity));
            m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
            // postMessageToList (m, "On-Screen Keyboard");
        }
    }

    void handleNoteOff (MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override{
        if (! isAddingFromMidiInput){
            MidiMessage m (MidiMessage::noteOff (midiChannel, midiNoteNumber));
            m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
            // postMessageToList (m, "On-Screen Keyboard");
        }
    }

    static String getMidiMessageDescription (const MidiMessage& m){
        if (m.isNoteOn())           return "Note on " + MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3);
        if (m.isNoteOff())          return "Note off " + MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3);
        if (m.isProgramChange())      return "Program change " + String (m.getProgramChangeNumber());
        if (m.isPitchWheel())       return "Pitch wheel " + String (m.getPitchWheelValue());
        if (m.isAftertouch())       return "After touch " + MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3) + ": " + String (m.getAfterTouchValue());
        if (m.isChannelPressure())  return "Channel pressure " + String (m.getChannelPressureValue());
        if (m.isAllNotesOff())      return "All notes off";
        if (m.isAllSoundOff())      return "All sound off";
        if (m.isMetaEvent())        return "Meta event";

        if (m.isController()){
            String name (MidiMessage::getControllerName (m.getControllerNumber()));
            if (name.isEmpty())
                name = "[" + String (m.getControllerNumber()) + "]";

            return "Controller " + name + ": " + String (m.getControllerValue());
        }

        return String::toHexString (m.getRawData(), m.getRawDataSize());
    }

    // void postMessageToList (const MidiMessage& message, const String& source){
    //     (new IncomingMessageCallback (this, message, source))->post();
    // }

    void addMessageToList(const MidiMessage& message, const String& source){
        const double time = message.getTimeStamp() - startTime;
        const int hours = ((int) (time / 3600.0)) % 24;
        const int minutes = ((int) (time / 60.0)) % 60;
        const int seconds = ((int) time) % 60;
        const int millis = ((int) (time * 1000.0)) % 1000;

        const String timecode (String::formatted ("%02d:%02d:%02d.%03d", hours, minutes, seconds, millis));
        const String description (getMidiMessageDescription(message));
        const String midiMessageString (timecode + " - " + description + " (" + source + ")");
        logMessage (midiMessageString);
    }

    void logMessage (const String& m){
        midiMessagesBox.moveCaretToEnd();
        midiMessagesBox.insertTextAtCaret(m + newLine);
    }

    void comboBoxChanged (ComboBox* box) override{
        if (box == &midiInputList){
            setMidiInput (midiInputList.getSelectedItemIndex());
        }
    }



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }
