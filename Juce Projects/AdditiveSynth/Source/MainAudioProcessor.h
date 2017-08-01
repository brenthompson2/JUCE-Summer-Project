/*
  ==============================================================================

    MainAudioProcessor.h
    Created: 28 Jul 2017 5:50:50pm
    Author:  Brendan Thompson

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "UserInterface.h"

// Constants
    const float MAX_VOLUME = 0.5f;
    const float MIN_FREQUENCY = 50.0f;
    const float MAX_FREQUENCY = 5000.0f;

// Structs

class MainAudioProcessor   : public AudioProcessor
{
public:

//==============================================================================
// Constructor & Destructor

	MainAudioProcessor();
	~MainAudioProcessor();

//==============================================================================
// Public Audio Functions

	void prepareToPlay (double sampleRate, int maximumExpectedSamplesPerBlock) override;
	void processBlock (AudioBuffer<float> &buffer, MidiBuffer &midiMessages) override;
	void releaseResources() override;

//==============================================================================
// Public UI Functions

	AudioProcessorEditor* createEditor() override { return new UserInterface(*this, parameters); }
	bool hasEditor() const override 		{return true;	}

private:


//==============================================================================
// Private Functions:

	void updateAngleDelta();


//==============================================================================
// Private Members:

	// General Synthesis
	Random randomGen;
	float volumeLevel;
    float nextSample;

	// Sine Wave Synthesis
    double currentSampleRate, currentAngle, angleDelta, currentFrequency;

    // Value Tree
    AudioProcessorValueTreeState parameters;

    // This thing
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainAudioProcessor)
};
