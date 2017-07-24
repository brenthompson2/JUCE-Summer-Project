/*
  ==============================================================================

    UserInterface.h
    Created: 24 Jul 2017 4:08:08pm
    Author:  Brendan Thompson

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class UserInterface    : public Component
{
public:
    UserInterface();
    ~UserInterface();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UserInterface)
};
