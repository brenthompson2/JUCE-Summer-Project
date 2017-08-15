/*
  ==============================================================================

    MainComponent.cpp
    Updated: 08/14/17
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
        numActiveSynths(1)
    {
        setSize (800, 600);
        // specify the number of input and output channels that we want to open
        setAudioChannels (0, 2);

        // Initialize the synths
        initSynths();
        resized();

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

        // Set Up the UI Components
        header.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        header.setButtonText("Brendan's First Synthesizer");
        addAndMakeVisible(header);
        footer.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        footer.setButtonText("Designed with JUCE");
        addAndMakeVisible(footer);
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

        updateAngleDelta();
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

        const int headerFooterHeight = 36;
        header.setBounds (area.removeFromTop (headerFooterHeight));
        footer.setBounds (area.removeFromBottom (headerFooterHeight));

        const int sidebarWidth = 80;
        sidebar = (area.removeFromLeft(sidebarWidth));
        Rectangle<int> mainVolumeRectangle(sidebar);
        mainVolumeRectangle.setPosition(mainVolumeRectangle.getX() + 5, mainVolumeRectangle.getY() + (sidebar.getHeight() / 2) - 10);
        mainVolumeRectangle.setSize(mainVolumeRectangle.getWidth() - 10, mainVolumeRectangle.getHeight() / 2);
        mainVolumeSlider.setBounds(mainVolumeRectangle);

        // Paint the Synthesizers
        const int contentItemHeight = 80;
        for (int i = 0; i < numActiveSynths; i++){
            if (synthArray[i].isActive){
                Rectangle<int> tempContentArea(area.removeFromTop (contentItemHeight));
                Rectangle<int> tempContentAreaTwo(area.removeFromTop (contentItemHeight));

                // Set The Volume Area
                (synthArray[i].volumeArea).setPosition(tempContentArea.getX(), tempContentArea.getY());
                (synthArray[i].volumeArea).setSize(tempContentArea.getWidth(), tempContentArea.getHeight());
                (synthArray[i].volumeSlider).setBounds((synthArray[i].volumeArea).getX() + sidebarWidth, (synthArray[i].volumeArea).getY(), (synthArray[i].volumeArea).getWidth() - sidebarWidth, (synthArray[i].volumeArea).getHeight());

                // Set The Frequency Area
                (synthArray[i].frequencyArea).setPosition(tempContentAreaTwo.getX(), tempContentAreaTwo.getY());
                (synthArray[i].frequencyArea).setSize(tempContentAreaTwo.getWidth(), tempContentAreaTwo.getHeight());
                (synthArray[i].frequencySlider).setBounds((synthArray[i].frequencyArea).getX() + sidebarWidth, (synthArray[i].frequencyArea).getY(), (synthArray[i].frequencyArea).getWidth() - sidebarWidth, (synthArray[i].frequencyArea).getHeight());
            }
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
                    updateAngleDelta();
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
            (synthArray[i].currentFrequency) = 500.0;
            (synthArray[i].volumeLevel) = 0.25;
            (synthArray[i].currentAngle) = 0.0;
            (synthArray[i].angleDelta) = 0.0;

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
        }
    }

    // Currently: for each channel, for each sample, for each active synth, manipulate the sample accordingly
    void MainContentComponent::generateAudio(const AudioSourceChannelInfo& bufferToFill){
        const int numChannels = bufferToFill.buffer->getNumChannels();
        const int numSamples = bufferToFill.numSamples;

        for (int channel = 0; channel < numChannels; channel++){
            float* const buffer = bufferToFill.buffer -> getWritePointer (channel, bufferToFill.startSample);
            float newSample;

            for (int sample; sample < numSamples; sample++){
                // Hardcoded White Noise
                // (synthArray[0].nextSample) = (randomGen.nextFloat() * 2.0f - 1.0f);

                // Hardcoded Sine Wave
                (synthArray[0].nextSample) = (float) std::sin (synthArray[0].currentAngle);
                (synthArray[0].currentAngle) += (synthArray[0].angleDelta);
                (synthArray[0].nextSample) = ((synthArray[0].nextSample) * (synthArray[0].volumeLevel)) * mainVolumeLevel;
                buffer[sample] = (synthArray[0].nextSample);

                // Less Hardcoded Sine Wave ***** FAILS HERE!?!?!?!?
                // int synthCursor = 0;
                // (synthArray[synthCursor].nextSample) = (float) std::sin (synthArray[synthCursor].currentAngle);
                // (synthArray[synthCursor].currentAngle) += (synthArray[synthCursor].angleDelta);
                // (synthArray[synthCursor].nextSample) = ((synthArray[synthCursor].nextSample) * (synthArray[synthCursor].volumeLevel)) * mainVolumeLevel;
                // buffer[sample] = (synthArray[synthCursor].nextSample);

                // Dynamic Sine Waves
                // buffer[sample] = 0.0f;
                // for (int i = 0; i < 1; i++){
                //     (synthArray[i].nextSample) = (float) std::sin (synthArray[i].currentAngle);
                //     (synthArray[i].currentAngle) += (synthArray[i].angleDelta);
                //     (synthArray[i].nextSample) = ((synthArray[i].nextSample) * (synthArray[i].volumeLevel)) * mainVolumeLevel;
                //     buffer[sample] = (synthArray[i].nextSample);
                // }
            }
        }
    }

    // updateAngleDelta
    void MainContentComponent::updateAngleDelta(){


        //// NEED TO OPTIMIZE!!!!
        /// *********************
        ///***********************
        for (int i = 0; i < MAX_SYNTHS; i++){
            // number of cycles necessary per each output sample, multiplied by length of sine wave cycle (2pi radians)
            const double cyclesPerSample = (synthArray[i].currentFrequency) / currentSampleRate;

            (synthArray[i].angleDelta) = cyclesPerSample * 2.0 * double_Pi;
        }
    }

//==============================================================================
// (This function is called by the app startup code to create our main component)
    Component* createMainContentComponent()     { return new MainContentComponent(); }