/*
==============================================================================

	UserInterface.cpp
    Updated: 27 Jul 2017
	Author:  Brendan Thompson

==============================================================================
*/

#include "UserInterface.h"

//==============================================================================
// Constructor & Destructor
	UserInterface::UserInterface(AudioProcessor& parent, AudioProcessorValueTreeState& parentVTS)
		:	AudioProcessorEditor (parent),
			valueTreeState (parentVTS)
	{
		// Set up the Volume Slider
        addAndMakeVisible(mainVolumeSlider);
        mainVolumeSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        mainVolumeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxLeft, false, 80, 30);
        volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "volumeLevel", mainVolumeSlider);
        addAndMakeVisible(mainVolumeLabel);
        mainVolumeLabel.setText("Volume", dontSendNotification);
        mainVolumeLabel.attachToComponent (&mainVolumeSlider, true);

        // Set up the Frequency Slider
        addAndMakeVisible(frequencySlider);
        frequencySlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        frequencySlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxLeft, false, 80, 30);
        frequencySlider.setSkewFactorFromMidPoint(500.0); // makes it feel more natural since the change is logarithmic (500 is now the midpoint)
        frequencyAttachment = new AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "currentFrequency", frequencySlider);
        addAndMakeVisible(frequencyLabel);
        frequencyLabel.setText("Frequency", dontSendNotification);
        frequencyLabel.attachToComponent (&frequencySlider, true);

        // Set Up the UI Components
        header.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        header.setButtonText("Brendan's Additive Synthesizer");
        addAndMakeVisible(header);
        footer.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        footer.setButtonText("Footer");
        addAndMakeVisible(footer);
        sidebar.setColour(TextButton::buttonColourId, Colours::grey);
        sidebar.setButtonText("Sidebar");
        addAndMakeVisible(sidebar);
        contentOne.setColour(TextButton::buttonColourId, Colours::grey);
        contentOne.setButtonText("contentOne");
        addAndMakeVisible(contentOne);
        contentTwo.setColour(TextButton::buttonColourId, Colours::grey);
        contentTwo.setButtonText("contentTwo");
        addAndMakeVisible(contentTwo);
	}

	UserInterface::~UserInterface()
	{
	}

//==============================================================================
// Public UI Functions

	void UserInterface::paint (Graphics& g)
	{
	}

	void UserInterface::resized()
    {
        Rectangle<int> area(getLocalBounds());

        const int headerFooterHeight = 36;
        header.setBounds (area.removeFromTop (headerFooterHeight));
        footer.setBounds (area.removeFromBottom (headerFooterHeight));

        const int sidebarWidth = 80;
        sidebar.setBounds (area.removeFromLeft (sidebarWidth));

        const int contentItemHeight = 80;
        Rectangle<int> contentOne(area.removeFromTop (contentItemHeight));
        Rectangle<int> contentTwo(area.removeFromTop (contentItemHeight));
        mainVolumeSlider.setBounds(contentOne.getX() + sidebarWidth, contentOne.getY(), contentOne.getWidth() - sidebarWidth, contentOne.getHeight()); // (getWidth() / 2) - 60, getHeight() / 2, 80, 100);
        frequencySlider.setBounds(contentTwo.getX() + sidebarWidth, contentTwo.getY(), contentTwo.getWidth() - sidebarWidth, contentTwo.getHeight()); // (getWidth() / 2) + 60, getHeight() / 2, 80, 100);
    }