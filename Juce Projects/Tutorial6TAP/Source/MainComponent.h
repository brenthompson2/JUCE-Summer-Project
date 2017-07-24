/*  Brendan Thompson
*   MainComponent.h
*
*   Header for the main UI made while following the 6th Tutorial by "The Audio Programmer"
*
*
*
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

// All the Code for a Class that handles the LookAndFeel
class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    OtherLookAndFeel(){
        setColour(Slider::rotarySliderOutlineColourId, Colours::chocolate);
        setColour(Slider::rotarySliderFillColourId, Colours::orange);
        setColour(Slider::thumbColourId, Colours::black);
    }
};


class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
    
    // Sliders
    Slider dial1;
    Slider dial2;

    // Look And Feel
    OtherLookAndFeel otherLookAndFeel;


};
