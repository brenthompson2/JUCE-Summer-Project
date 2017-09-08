/*
  ==============================================================================

    MainComponent.cpp
    Updated: 08/21/17
    Author:  Brendan Thompson

    Main Audio Processor for the Additive Synthesizer

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
// Constructor & Destructor

    MainContentComponent::MainContentComponent()
    :
        currentSampleRate (0.0),
        mainVolumeLevel(0.25),
        numActiveSynths(5)
    {
        setSize (800, 600);
        // specify the number of input and output channels that we want to open
        setAudioChannels (0, 2);

        // Initialize the synths
        initSynths();
        initUI();
    }

    MainContentComponent::~MainContentComponent()
    {
        shutdownAudio();
    }

//==============================================================================
// Public Audio Functions

    void MainContentComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
    {
        currentSampleRate = sampleRate;
    }

    void MainContentComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
    {
        generateAudio(bufferToFill);
    }

    void MainContentComponent::releaseResources()
    {
    }

//==============================================================================
// Public UI Functions

    void MainContentComponent::paint (Graphics& g)
    {
    }

    void MainContentComponent::resized()
    {
        Rectangle<int> area(getLocalBounds());

        // Header
        const int headerFooterHeight = 36;
        header.setBounds (area.removeFromTop (headerFooterHeight));
        footer.setBounds (area.removeFromBottom (headerFooterHeight));

        // Sidebar
        const int sidebarWidth = 80;
        sidebar = (area.removeFromLeft(sidebarWidth));
            // mainNumHarmonicsRectangle.setPosition();
            // boxNumHarmonics.setBounds(mainNumHarmonicsRectangle);

            // Main Volume Slider
            Rectangle<int> mainVolumeRectangle(sidebar);
            mainVolumeRectangle.setPosition(mainVolumeRectangle.getX() + 5, mainVolumeRectangle.getY() + (sidebar.getHeight() / 2) - 10);
            mainVolumeRectangle.setSize(mainVolumeRectangle.getWidth() - 10, mainVolumeRectangle.getHeight() / 2);
            mainVolumeSlider.setBounds(mainVolumeRectangle);

        // Paint the Main Content Area
        const int contentItemHeight = 50;
        const int toggleBtnWidth = 40;
        for (int i = 0; i < numActiveSynths; i++){
            Rectangle<int> tempSynthArea(area.removeFromTop (contentItemHeight));
            Rectangle<int> tempToggleArea(tempSynthArea.removeFromLeft (toggleBtnWidth));
            Rectangle<int> emptyContentArea(area.removeFromTop (contentItemHeight));

            // Set the Toggle Button Area
            (synthArray[i].toggleBtnArea).setPosition(tempToggleArea.getX(), tempToggleArea.getY());
            (synthArray[i].toggleBtnArea).setSize(tempToggleArea.getWidth(), tempToggleArea.getHeight());
            (synthArray[i].btnIsActive).setBounds((synthArray[i].toggleBtnArea).getX(), (synthArray[i].toggleBtnArea).getY(), (synthArray[i].toggleBtnArea).getWidth(), (synthArray[i].toggleBtnArea).getHeight());

            // Set The Volume Area
            (synthArray[i].volumeArea).setPosition(tempSynthArea.getX() + toggleBtnWidth, tempSynthArea.getY());
            (synthArray[i].volumeArea).setSize(tempSynthArea.getWidth() - toggleBtnWidth, tempSynthArea.getHeight());
            (synthArray[i].volumeSlider).setBounds((synthArray[i].volumeArea).getX() + sidebarWidth, (synthArray[i].volumeArea).getY(), (synthArray[i].volumeArea).getWidth() - sidebarWidth, (synthArray[i].volumeArea).getHeight());

            // Set The Frequency Area
            (synthArray[i].frequencyArea).setPosition(tempSynthArea.getX() + toggleBtnWidth, tempSynthArea.getY() + (contentItemHeight / 2));
            (synthArray[i].frequencyArea).setSize(tempSynthArea.getWidth() - toggleBtnWidth, tempSynthArea.getHeight());
            (synthArray[i].frequencySlider).setBounds((synthArray[i].frequencyArea).getX() + sidebarWidth, (synthArray[i].frequencyArea).getY(), (synthArray[i].frequencyArea).getWidth() - sidebarWidth, (synthArray[i].frequencyArea).getHeight());
        }
    }

//==============================================================================
// Slider::Listener Functions

    void MainContentComponent::sliderValueChanged (Slider* slider){

        /// *********************
        // *************** Don't Search Every Single Slider!!!!!!
        /// *********   Need To Optimize This!!!!!!!
        //// ****************** How could I make it send some sort of ID?
        if (slider == &mainVolumeSlider){
           mainVolumeLevel = mainVolumeSlider.getValue();
            return;
        }

        for (int i = 0; i < numActiveSynths; i++){
            if (slider == &(synthArray[i].volumeSlider)){
               (synthArray[i].volumeLevel) = (synthArray[i].volumeSlider).getValue();
                return;
            }
            if (slider == &(synthArray[i].frequencySlider)){
                (synthArray[i].currentFrequency) = (synthArray[i].frequencySlider).getValue();
                if (currentSampleRate > 0.0){
                    (synthArray[i].angleDelta) = getUpdatedAngleDelta((synthArray[i].currentFrequency));
                }
                return;
            }
        }
    }



//==============================================================================
//==============================================================================
//==============================================================================
// Private Audio Functions

    void MainContentComponent::initSynths(){
        for (int i = 0; i < MAX_SYNTHS; i++){

            // Audio
            (synthArray[i].currentFrequency) = 500.0f;
            (synthArray[i].volumeLevel) = 0.25;
            (synthArray[i].currentAngle) = 0.0;
            (synthArray[i].angleDelta) = getUpdatedAngleDelta(synthArray[i].currentFrequency);

            if (i < numActiveSynths){
                (synthArray[i].isActive) = true;
            }
            else {
                (synthArray[i].isActive) = false;
            }

            // Volume Slider
            addAndMakeVisible(synthArray[i].volumeSlider);
            (synthArray[i].volumeSlider).addListener(this);
            (synthArray[i].volumeSlider).setRange(0.0, MAX_VOLUME);
            (synthArray[i].volumeSlider).setSliderStyle(Slider::SliderStyle::LinearHorizontal);
            (synthArray[i].volumeSlider).setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxLeft, false, 80, 30);
            (synthArray[i].volumeSlider).setValue((synthArray[i].volumeLevel), dontSendNotification);
            addAndMakeVisible((synthArray[i].volumeSlider));
            (synthArray[i].volumeLabel).setText("Volume", dontSendNotification);
            (synthArray[i].volumeLabel).attachToComponent (&synthArray[i].volumeSlider, true);

            // Frequency Slider
            addAndMakeVisible(synthArray[i].frequencySlider);
            (synthArray[i].frequencySlider).addListener(this);
            (synthArray[i].frequencySlider).setRange(MIN_FREQUENCY, MAX_FREQUENCY);
            (synthArray[i].frequencySlider).setSliderStyle(Slider::SliderStyle::LinearHorizontal);
            (synthArray[i].frequencySlider).setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxLeft, false, 80, 30);
            (synthArray[i].frequencySlider).setSkewFactorFromMidPoint(500.0); // makes it feel more natural since the change is logarithmic (500 is now the midpoint)
            (synthArray[i].frequencySlider).setValue((synthArray[i].currentFrequency), dontSendNotification);
            addAndMakeVisible((synthArray[i].frequencyLabel));
            (synthArray[i].frequencyLabel).setText("Frequency", dontSendNotification);
            (synthArray[i].frequencyLabel).attachToComponent (&(synthArray[i].frequencySlider), true);

            // UI Components
            addAndMakeVisible(synthArray[i].btnIsActive);
            (synthArray[i].btnIsActive).setToggleState (true, dontSendNotification);
            // (synthArray[i].btnIsActive).addListener(this);
            // (synthArray[i].btnIsActive).setButtonText("Active");
        }
    }

    // Currently: for each channel, for each sample, for each active synth, manipulate the sample accordingly
    void MainContentComponent::generateAudio(const AudioSourceChannelInfo& bufferToFill){
        const int numChannels = bufferToFill.buffer->getNumChannels();
        const int numSamples = bufferToFill.numSamples; //std::min(bufferToFill.numSamples, MAX_SAMPLES_PER_BLOCK);
        float synthWeight = (1.0f / (float) numActiveSynths);
        float mainNextSample;
        // Random randomGen;   // Only used when generating white noise

        // Save Original Angle
        for (int i = 0; i < numActiveSynths; i++){
            (synthArray[i].lastAngle) = (synthArray[i].currentAngle);
        }

        for (int channel = 0; channel < numChannels; channel++){
            float* const buffer = bufferToFill.buffer -> getWritePointer (channel, bufferToFill.startSample);

            // Reset Angle back to Original
            for (int i = 0; i < numActiveSynths; i++){
                (synthArray[i].currentAngle) = (synthArray[i].lastAngle);
                (synthArray[i].angleDelta) = getUpdatedAngleDelta(synthArray[i].currentFrequency);
            }

            for (int sample = 0; sample < numSamples; sample++){
                // Hardcoded White Noise
                // (synthArray[0].nextSample) = (randomGen.nextFloat() * 2.0f - 1.0f);
                // buffer[sample] = (synthArray[0].nextSample);

                // Hardcoded Sine Wave
                // (synthArray[0].nextSample) = (float) std::sin (synthArray[0].currentAngle);
                // (synthArray[0].nextSample) = ((synthArray[0].nextSample) * (synthArray[0].volumeLevel)) * mainVolumeLevel;
                // buffer[sample] = (synthArray[0].nextSample);
                // (synthArray[0].currentAngle) += (synthArray[0].angleDelta);

                // Less Hardcoded Sine Wave *** FAILS HERE!?!?!?!? ***
                // int synthCursor = 0;
                // (synthArray[synthCursor].nextSample) = (float) std::sin (synthArray[synthCursor].currentAngle);
                // (synthArray[synthCursor].nextSample) = ((synthArray[synthCursor].nextSample) * (synthArray[synthCursor].volumeLevel)) * mainVolumeLevel;
                // buffer[sample] = (synthArray[synthCursor].nextSample);
                // (synthArray[synthCursor].currentAngle) += (synthArray[synthCursor].angleDelta);

                // Additive Syntheses    with some global member variables that should be local temps (synthCursor, mainNextSample, randomGen)
                // formula: mainSample = mainSample + (sin(angle) * volume * weight)
                mainNextSample = 0;
                for (int synthCursor = 0; synthCursor < numActiveSynths; synthCursor++){
                    if ((synthArray[synthCursor].btnIsActive).getToggleState()){
                        (synthArray[synthCursor].nextSample) = (float) std::sin (synthArray[synthCursor].currentAngle);
                        (synthArray[synthCursor].nextSample) = ((synthArray[synthCursor].nextSample) * (synthArray[synthCursor].volumeLevel)) * mainVolumeLevel;
                        (synthArray[synthCursor].currentAngle) += (synthArray[synthCursor].angleDelta);
                        mainNextSample = mainNextSample + ((synthArray[synthCursor].nextSample) * synthWeight);
                    }
                }
                buffer[sample] = mainNextSample * mainVolumeLevel;

            //     if (!(sample % 50)) {std::cout << "Channel: " << channel << "\tSample: " << sample <<"\tBuffer: " << buffer[sample] << std::endl;}   // print every 50 samples
            }
        }
    }

    // getUpdatedAngleDelta = returns the degree of change necessary to create a sine wave in one cycle given the desired frequency
    double MainContentComponent::getUpdatedAngleDelta(double frequency){
        // number of cycles necessary per each output sample, multiplied by length of sine wave cycle (2pi radians)
        const double cyclesPerSample = (frequency) / currentSampleRate;
        return (cyclesPerSample * 2.0 * double_Pi);
    }


//==============================================================================
// Private UI Functions:

    void MainContentComponent::initUI(){
        // Set up the Main Volume Slider
        addAndMakeVisible(mainVolumeSlider);
        mainVolumeSlider.addListener(this);
        mainVolumeSlider.setRange(0.0, MAX_VOLUME);
        mainVolumeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        mainVolumeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 80, 30);
        mainVolumeSlider.setValue(mainVolumeLevel, dontSendNotification);
        addAndMakeVisible(mainVolumeLabel);
        mainVolumeLabel.setText("Volume", dontSendNotification);
        mainVolumeLabel.attachToComponent (&mainVolumeSlider, false);

        // Set Up the UI TextButton Components
        header.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        header.setButtonText("Brendan's First Synthesizer");
        addAndMakeVisible(header);
        footer.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        footer.setButtonText("Designed with JUCE");
        addAndMakeVisible(footer);

        resized();
    }

//==============================================================================
// (This function is called by the app startup code to create our main component)
    Component* createMainContentComponent()     { return new MainContentComponent(); }