/*
  ==============================================================================

    MainComponent.h
    Created: 24 Jul 2017 4:12:57pm
    Author:  Brendan Thompson

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MainContentComponent   : public AudioAppComponent
{
public:

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
    // Your private member variables go here...

	int numChannels;
    int numSamples;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};