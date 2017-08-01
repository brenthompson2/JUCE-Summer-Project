/*
  ==============================================================================

    SynthForAdding.h
    Updated: 27 Jul 2017
    Author:  Brendan Thompson

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

// Symbolic Constants

//==============================================================================
/*
*/
class SynthForAdding    : public Component
{
public:

//==============================================================================
// Constructor & Destructor
    SynthForAdding();
    ~SynthForAdding();

//==============================================================================
// Public Audio Functions

	void prepareToPlay (int samplesPerBlockExpected, double sampleRate);

	void generateAudio (const AudioSourceChannelInfo& bufferToFill);

//==============================================================================
// Public UI Functions

    void paint (Graphics&) override;
    void resized() override;

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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthForAdding)


};

