/*
  ==============================================================================

    BasicAudioProcessor.h
    Updated: 08/06/17
    Author:  Brendan Thompson

    A Basic Audio Processor that inherits from the AudioProcessor class

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

// Symbolic Constants

// Structs

class BasicAudioProcessor   : public AudioProcessor
{
public:
//==============================================================================
// Public Members:
	static const uint32 BASIC_PROCESSOR_ID = 5;

//==============================================================================
// Constructor & Destructor

	BasicAudioProcessor();
	~BasicAudioProcessor();

	bool hasEditor() const override 					{return true; }
	AudioProcessorEditor* createEditor() override;

//==============================================================================
// Public Audio Functions

	void prepareToPlay (double sampleRate, int samplesPerBlockExpected) override;

	void processBlock (AudioBuffer<double>& buffer, MidiBuffer& midiMessages) override;

    void releaseResources() override;



private:
//==============================================================================
// Private Members:
    AudioBuffer<double> delayBufferDouble;


//==============================================================================
// Private Functions:
	template <typename FloatType>
	void process (AudioBuffer<FloatType>& buffer, MidiBuffer& midiMessages,	AudioBuffer<FloatType>& delayBuffer);



//==============================================================================
// This thing
    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicAudioProcessor)
};