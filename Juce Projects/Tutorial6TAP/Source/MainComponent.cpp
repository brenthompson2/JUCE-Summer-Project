/*  Brendan Thompson
*   MainComponent.cpp
*
*   Header for the main UI made while following the 6th Tutorial by "The Audio Programmer"
*
*
*
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);
    addAndMakeVisible(dial1);
    addAndMakeVisible(dial2);

    dial1.setSliderStyle(Slider::SliderStyle::Rotary);
    dial1.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    dial2.setSliderStyle(Slider::SliderStyle::Rotary);
    dial2.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);

    // Manipulating Look And Feel
    dial1.setLookAndFeel(&otherLookAndFeel);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
}

// called when the MainContentComponent is resized.
void MainContentComponent::resized()
{
    const int border = 20;
    const int dialWidth = (getWidth() / 2) - border;
    const int dialHeight = getHeight() - border - 100;

    dial1.setBounds(border, border, dialWidth, dialHeight);
    dial2.setBounds((getWidth() / 2), border, dialWidth, dialHeight);
}
