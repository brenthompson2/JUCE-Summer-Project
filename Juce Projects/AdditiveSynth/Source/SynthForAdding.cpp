/*
  ==============================================================================

    SynthForAdding.cpp
    Updated: 08/06/07
    Author:  Brendan Thompson

  ==============================================================================
*/

#include "SynthForAdding.h"

//==============================================================================
// Constructor & Destructor

    SynthForAdding::SynthForAdding()
    :
        currentSampleRate (0.0),
        currentAngle(0.0),
        angleDelta(0.0),
        currentFrequency(500.0),
        volumeLevel(0.25)
    {

        // Set up the Volume Slider
        addAndMakeVisible(volumeSlider);
        volumeSlider.addListener(this);
        volumeSlider.setRange(0.0, MAX_VOLUME);
        volumeSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        volumeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxLeft, false, 80, 30);
        volumeSlider.setValue(volumeLevel, dontSendNotification);
        addAndMakeVisible(volumeLabel);
        volumeLabel.setText("Volume", dontSendNotification);
        volumeLabel.attachToComponent (&volumeSlider, true);

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
        volumeArea.setColour(TextButton::buttonColourId, Colours::grey);
        volumeArea.setButtonText("volumeArea");
        addAndMakeVisible(volumeArea);
        frequencyArea.setColour(TextButton::buttonColourId, Colours::grey);
        frequencyArea.setButtonText("frequencyArea");
        addAndMakeVisible(frequencyArea);
    }

    SynthForAdding::~SynthForAdding()
    {
    }

//==============================================================================
// Public Audio Functions

    void SynthForAdding::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
    {
        currentSampleRate = sampleRate;
        updateAngleDelta();
    }

    void SynthForAdding::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
    {
        const int numChannels = bufferToFill.buffer->getNumChannels();
        const int numSamples = bufferToFill.numSamples;
        for (int channel = 0; channel < numChannels; channel++){
            float* const buffer = bufferToFill.buffer -> getWritePointer (channel, bufferToFill.startSample);
            for (int sample; sample < numSamples; sample++){
                // nextSample = (randomGen.nextFloat() * 2.0f - 1.0f); // For Randomly generated White Noise
                nextSample = (float) std::sin (currentAngle);
                currentAngle += angleDelta;
                buffer[sample] = nextSample * volumeLevel;
            }
        }
    }

    void SynthForAdding::releaseResources()
    {
    }

//==============================================================================
// Public UI Functions

    void SynthForAdding::paint (Graphics& g)
    {
    }

    void SynthForAdding::resized()
    {
    	Rectangle<int> area(getLocalBounds());
        volumeSlider.setBounds(area.getX() + 80, area.getY(), area.getWidth() - 80, area.getHeight()); // (getWidth() / 2) - 60, getHeight() / 2, 80, 100);
        frequencySlider.setBounds(area.getX() + 80, area.getY(), area.getWidth() - 80, area.getHeight()); // (getWidth() / 2) + 60, getHeight() / 2, 80, 100);
    }

//==============================================================================
// Slider::Listener Functions

    void SynthForAdding::sliderValueChanged (Slider* slider){
        if (slider == &volumeSlider){
           volumeLevel = volumeSlider.getValue();
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
    void SynthForAdding::updateAngleDelta(){
        // number of cycles necessary per each output sample, multiplied by length of sine wave cycle (2pi radians)
        const double cyclesPerSample = currentFrequency / currentSampleRate;
        angleDelta = cyclesPerSample * 2.0 * double_Pi;
    }

//==============================================================================
// (This function is called by the app startup code to create our main component)
    Component* createSynthForAdding()     { return new SynthForAdding(); }