/*
  ==============================================================================

    MainComponent.h
    Updated: 27 Jul 2017
    Author:  Brendan Thompson

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

// Constants

// Structs

class MainContentComponent   : public AudioAppComponent,
                            public Slider::Listener
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

//==============================================================================
// Slider::Listener Functions

    void sliderValueChanged (Slider* slider) override;

private:


//==============================================================================
// Private Functions:


//==============================================================================
// Private Members:

    // This thing
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};