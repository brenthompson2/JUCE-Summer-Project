/*
  ==============================================================================

    MainComponent.h
    Updated: 08/06/07
    Author:  Brendan Thompson

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthForAdding.h"

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
// Private Audio Members:

    float mainVolumeLevel;
    SynthForAdding* firstSynth;

//==============================================================================
// Private UI Members:

    // Rectangles
    Rectangle<int> area;
    TextButton header;
    TextButton footer;
    Rectangle<int> sidebar;
    TextButton contentOne;
    TextButton contentTwo;

    // Sliders
    Slider mainVolumeSlider;
    Label mainVolumeLabel;


//==============================================================================
// Private Functions:


    // This thing
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};