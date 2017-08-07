/*
  ==============================================================================

    SynthForAdding.h
    Updated: 08/06/07
    Author:  Brendan Thompson

    A synthesizer object made for use with an additive synth

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

// Symbolic Constants
    const float MAX_VOLUME = 0.5f;
    const float MIN_FREQUENCY = 50.0f;
    const float MAX_FREQUENCY = 5000.0f;

// Structs

class SynthForAdding : public AudioAppComponent,
                            public Slider::Listener
{
public:

//==============================================================================
// Constructor & Destructor

    SynthForAdding();
    ~SynthForAdding();

//==============================================================================
// Public Audio Functions

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

//==============================================================================
// Public UI Functions

    void paint (Graphics& g) override;
    void resized() override;

//==============================================================================
// Slider::Listener Functions

    void sliderValueChanged (Slider* slider) override;

private:


//==============================================================================
// Private Functions:

    void updateAngleDelta();


//==============================================================================
// Private Members:

    // Rectangles
    TextButton volumeArea;
    TextButton frequencyArea;

    // Sliders
    Slider volumeSlider;
    Label volumeLabel;
    Slider frequencySlider;
    Label frequencyLabel;

    // General Synthesis
    Random randomGen;
    float volumeLevel;
    float nextSample;

    // Sine Wave Synthesis
    double currentSampleRate, currentAngle, angleDelta, currentFrequency;

    // This thing
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthForAdding)
};