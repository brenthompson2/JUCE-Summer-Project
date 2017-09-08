/*
  ==============================================================================

    MainComponent.cpp
    Updated: 27 Jul 2017
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
        currentAngle(0.0),
        angleDelta(0.0),
        currentFrequency(500.0),
        volumeLevel(0.25)
    {
        setSize (800, 600);
        // specify the number of input and output channels that we want to open
        setAudioChannels (0, 4);

        // Set up the Volume Slider
        addAndMakeVisible(mainVolumeSlider);
        mainVolumeSlider.addListener(this);
        mainVolumeSlider.setRange(0.0, MAX_VOLUME);
        mainVolumeSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        mainVolumeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxLeft, false, 80, 30);
        mainVolumeSlider.setValue(volumeLevel, dontSendNotification);
        addAndMakeVisible(mainVolumeLabel);
        mainVolumeLabel.setText("Volume", dontSendNotification);
        mainVolumeLabel.attachToComponent (&mainVolumeSlider, true);

        // Set up the Frequency Slider
        addAndMakeVisible(frequencySlider);
        frequencySlider.addListener(this);
        frequencySlider.setRange(MIN_FREQUENCY, MAX_FREQUENCY);
        frequencySlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        frequencySlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxLeft, false, 80, 30);
        frequencySlider.setSkewFactorFromMidPoint(500.0); // makes it feel more natural since the change is logarithmic (500 is now the midpoint)
        frequencySlider.setValue(currentFrequency, dontSendNotification);
        addAndMakeVisible(frequencyLabel);
        frequencyLabel.setText("Frequency", dontSendNotification);
        frequencyLabel.attachToComponent (&frequencySlider, true);

        // Set Up the UI Components
        header.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        header.setButtonText("Brendan's First Synthesizer");
        addAndMakeVisible(header);
        footer.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        footer.setButtonText("Footer");
        addAndMakeVisible(footer);
        sidebar.setColour(TextButton::buttonColourId, Colours::grey);
        sidebar.setButtonText("Sidebar");
        addAndMakeVisible(sidebar);
        contentOne.setColour(TextButton::buttonColourId, Colours::grey);
        contentOne.setButtonText("contentOne");
        addAndMakeVisible(contentOne);
        contentTwo.setColour(TextButton::buttonColourId, Colours::grey);
        contentTwo.setButtonText("contentTwo");
        addAndMakeVisible(contentTwo);
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
        const int numChannels = bufferToFill.buffer->getNumChannels();
        const int numSamples = bufferToFill.numSamples;
        double originalAngle = currentAngle;
        for (int channel = 0; channel < numChannels; channel++){
            float* const buffer = bufferToFill.buffer -> getWritePointer (channel, bufferToFill.startSample);
            currentAngle = originalAngle;
            updateAngleDelta();
            for (int sample = 0; sample < numSamples; sample++){
                // nextSample = (randomGen.nextFloat() * 2.0f - 1.0f); // For Randomly generated White Noise
                const float nextSample = (float) std::sin (currentAngle);
                currentAngle += angleDelta;
                buffer[sample] = nextSample * volumeLevel;
                if (!(sample % 100)) { std::cout << buffer[sample] << std::endl;}
            }
        }
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
        sidebar.setBounds (area.removeFromLeft (sidebarWidth));

        const int contentItemHeight = 80;
        Rectangle<int> contentOne(area.removeFromTop (contentItemHeight));
        Rectangle<int> contentTwo(area.removeFromTop (contentItemHeight));
        mainVolumeSlider.setBounds(contentOne.getX() + sidebarWidth, contentOne.getY(), contentOne.getWidth() - sidebarWidth, contentOne.getHeight()); // (getWidth() / 2) - 60, getHeight() / 2, 80, 100);
        frequencySlider.setBounds(contentTwo.getX() + sidebarWidth, contentTwo.getY(), contentTwo.getWidth() - sidebarWidth, contentTwo.getHeight()); // (getWidth() / 2) + 60, getHeight() / 2, 80, 100);
    }

//==============================================================================
// Slider::Listener Functions

    void MainContentComponent::sliderValueChanged (Slider* slider){
        if (slider == &mainVolumeSlider){
           volumeLevel = mainVolumeSlider.getValue();
        }
        if (slider == &frequencySlider){
            currentFrequency = frequencySlider.getValue();
            if (currentSampleRate > 0.0){
                updateAngleDelta();
            }
        }
    }



//==============================================================================
//==============================================================================
//==============================================================================
// Private Functions

    // updateAngleDelta
    void MainContentComponent::updateAngleDelta(){
        // number of cycles necessary per each output sample, multiplied by length of sine wave cycle (2pi radians)
        const double cyclesPerSample = currentFrequency / currentSampleRate;
        angleDelta = cyclesPerSample * 2.0 * double_Pi;
    }

//==============================================================================
// (This function is called by the app startup code to create our main component)
    Component* createMainContentComponent()     { return new MainContentComponent(); }