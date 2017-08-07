/*
  ==============================================================================

    BasicAudioProcessorEditor.h
    Updated: 08/06/17
    Author:  Brendan Thompson

    A basic user interface that inherits from the AudioProcessorEditor class

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "BasicAudioProcessor.h"

//==============================================================================
/*
*/
class BasicAudioProcessorEditor    : public AudioProcessorEditor
{
public:
//==============================================================================
// Public Member Variables

// Symbolic Constants

//==============================================================================
// Constructor & Destructor
    BasicAudioProcessorEditor (BasicAudioProcessor&);
    ~BasicAudioProcessorEditor ();

//==============================================================================
// Public UI Functions
    void paint (Graphics&) override;
    void resized() override;

//==============================================================================
// Slider::Listener Functions

    //void sliderValueChanged (Slider* slider) override;

private:

//==============================================================================
// Private Member Variables

    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicAudioProcessorEditor)
};

