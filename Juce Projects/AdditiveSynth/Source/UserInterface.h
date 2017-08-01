/*
  ==============================================================================

    UserInterface.h
    Updated: 28 Jul 2017
    Author:  Brendan Thompson

    Description: A UserInterface that inherits from AudioProcessorEditor in order to
                attach to a ValueTree of a AudioProcessor parent

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class UserInterface    :    public AudioProcessorEditor
{
public:

//==============================================================================
// Public Constants


//==============================================================================
// Public Symbolic Constants


//==============================================================================
// Public Member Variables

//==============================================================================
// Constructor & Destructor
    UserInterface(AudioProcessor& parent, AudioProcessorValueTreeState& parentVTS);
    ~UserInterface();

//==============================================================================
// Public UI Functions
    void paint (Graphics&) override;
    void resized() override;

private:

//==============================================================================
// Private Member Variables

    // Value Tree
    AudioProcessorValueTreeState& valueTreeState;

    // Rectangles
    TextButton header;
    TextButton footer;
    TextButton sidebar;
    TextButton contentOne;
    TextButton contentTwo;

    // Sliders
    Slider mainVolumeSlider;
    Label mainVolumeLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;

    Slider frequencySlider;
    Label frequencyLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> frequencyAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UserInterface)
};
