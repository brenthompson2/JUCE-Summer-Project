/*
  ==============================================================================

    SynthForAdding.cpp
    Updated: 27 Jul 2017
    Author:  Brendan Thompson

  ==============================================================================
*/

#include "SynthForAdding.h"

//==============================================================================
// Constructor & Destructor

	SynthForAdding::SynthForAdding()
	{
		//synthComponent thisSynth;
	}

	SynthForAdding::~SynthForAdding()
	{
	}

//==============================================================================
// Public Audio Functions

	void SynthForAdding::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
	{
	}

	void SynthForAdding::generateAudio (const AudioSourceChannelInfo& bufferToFill)
	{    
	}

//==============================================================================
// Public UI Functions

	void SynthForAdding::paint (Graphics& g)
	{
	}

	void SynthForAdding::resized()
	{
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