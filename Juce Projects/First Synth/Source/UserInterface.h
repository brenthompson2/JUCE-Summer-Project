/*
  ==============================================================================

    UserInterface.h
    Updated: 27 Jul 2017
    Author:  Brendan Thompson

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class UserInterface    : public Component,
                            public Slider::Listener
{
public:

//==============================================================================
// Public Member Variables

// Symbolic Constants

//==============================================================================
// Constructor & Destructor
    UserInterface();
    ~UserInterface();

//==============================================================================
// Public UI Functions
    void paint (Graphics&) override;
    void resized() override;

//==============================================================================
// Slider::Listener Functions

    void sliderValueChanged (Slider* slider) override;

private:

//==============================================================================
// Private Member Variables

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UserInterface)
};
