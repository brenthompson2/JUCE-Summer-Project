/*
  ==============================================================================

    BasicAudioProcessor.cpp
    Updated: 08/06/17
    Author:  Brendan Thompson

    A Basic Audio Processor that inherits from the AudioProcessor class

  ==============================================================================
*/

#include "BasicAudioProcessor.h"
#include "BasicAudioProcessorEditor.h"

//==============================================================================
// Constructor & Destructor

	BasicAudioProcessor::BasicAudioProcessor(){
		//BasicAudioProcessorEditor* theEditor = createEditor();
	}

	BasicAudioProcessor::~BasicAudioProcessor(){

	}

	// Create The Editor
	AudioProcessorEditor* BasicAudioProcessor::createEditor(){
    	return new BasicAudioProcessorEditor (*this);
    }

    // This creates new instances of the processor? I don't think it's used
	AudioProcessor* JUCE_CALLTYPE createPluginFilter()
	{
	    return new BasicAudioProcessor;
	}

//==============================================================================
// Public Audio Functions

	void BasicAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlockExpected){

	}

	void BasicAudioProcessor::processBlock (AudioBuffer<double>& buffer, MidiBuffer& midiMessages){
        process (buffer, midiMessages, delayBufferDouble);
    }

    void BasicAudioProcessor::releaseResources(){

    }

//==============================================================================
// Private Methods:

    template <typename FloatType>
	void BasicAudioProcessor::process (AudioBuffer<FloatType>& buffer, MidiBuffer& midiMessages,	AudioBuffer<FloatType>& delayBuffer){

	}




