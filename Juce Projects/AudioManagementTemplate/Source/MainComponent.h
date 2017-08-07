/*
  ==============================================================================

    MainComponent.h
    Updated: 08/06/2017
    Author:  Brendan Thompson

	MainComponent for an Audio Plugin
	Controls the AudioDeviceManager & AudioProcessorGraph

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "BasicAudioProcessor.h"
#include "BasicAudioProcessorEditor.h"

// Symbolic Constants
	const int NUMBER_INPUT_CHANNELS = 2;
	const int NUMBER_OUTPUT_CHANNELS = 2;

// Structs

class MainContentComponent   : public AudioAppComponent
{
public:
//==============================================================================
// Public Members:

//==============================================================================
// Constructor & Destructor

	MainContentComponent();
	~MainContentComponent();

//==============================================================================
// Public Audio Functions

	void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
	void releaseResources() override;

//==============================================================================
// Public UI Functions

	void paint (Graphics& g) override;
	void resized() override;

private:
//==============================================================================
// Private Members:
	AudioDeviceManager mainDeviceManager;
	AudioProcessorPlayer mainPlayer;
	AudioProcessorGraph mainGraph;
	AudioProcessor* firstProcessor;

//==============================================================================
// Private Functions:
	void initialiseAudioProcessingHierarchy();

//==============================================================================
// Xml Functions:
	//XmlElement* createXml();

//==============================================================================
// This thing
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};