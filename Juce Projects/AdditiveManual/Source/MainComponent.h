/*
  ==============================================================================

    MainComponent.h
    Updated: 08/13/17
    Author:  Brendan Thompson

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

// Symbolic Constants
    const float MAX_VOLUME = 0.5f;
    const float MIN_FREQUENCY = 50.0f;
    const float MAX_FREQUENCY = 5000.0f;
    const int MAX_SYNTHS = 10;

// Structs
    struct synthComponent
    {
    	bool isActive;

    	// Volume & Frequency
    	Slider volumeSlider;
    	Label volumeLabel;
		float volumeLevel;
    	Slider frequencySlider;
    	Label frequencyLabel;
    	double currentFrequency;

		// Audio Synthesis Members
	    float nextSample;
    	double currentAngle;
    	double angleDelta;

    	// UI
    	Rectangle<int> volumeArea;
    	Rectangle<int> frequencyArea;
    };

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
// Private Audio Functions:

	void initSynths();

	void generateAudio(const AudioSourceChannelInfo& bufferToFill);

	void updateAngleDelta();


//==============================================================================
// Private Members:

	// Audio
	float mainVolumeLevel;
    double currentSampleRate;
	Random randomGen;
	float mainNextSample;

	// Array of Synths
	int numActiveSynths;
	synthComponent synthArray[MAX_SYNTHS];

    // Rectangles
    TextButton header;
    TextButton footer;
    Rectangle<int> sidebar;

    // Sliders
    Slider mainVolumeSlider;
    Label mainVolumeLabel;

    // This thing
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};