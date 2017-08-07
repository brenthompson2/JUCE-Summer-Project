/*
  ==============================================================================

    MainComponent.cpp
    Updated: 08/06/07
    Author:  Brendan Thompson

    Main Audio Processor for the Additive Synthesizer

  ==============================================================================
*/

#include "MainComponent.h"
#include "SynthForAdding.h"

//==============================================================================
// Constructor & Destructor

    MainContentComponent::MainContentComponent()
    {
        setSize (800, 600);
        // specify the number of input and output channels that we want to open
        setAudioChannels (0, 4);

        // Set up the Main Volume Slider
        addAndMakeVisible(mainVolumeSlider);
        mainVolumeSlider.addListener(this);
        mainVolumeSlider.setRange(0.0, 100);
        mainVolumeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        mainVolumeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 80, 30);
        mainVolumeSlider.setValue(mainVolumeLevel, dontSendNotification);
        addAndMakeVisible(mainVolumeLabel);
        mainVolumeLabel.setText("Volume", dontSendNotification);
        mainVolumeLabel.attachToComponent (&mainVolumeSlider, false);

        // Set Up the UI Components
        header.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        header.setButtonText("Brendan's Additive Synthesizer");
        addAndMakeVisible(header);
        footer.setColour(TextButton::buttonColourId, Colours::cornflowerblue);
        footer.setButtonText("Footer");
        addAndMakeVisible(footer);
        // sidebar.setColour(TextButton::buttonColourId, Colours::grey);
        // sidebar.setButtonText("Sidebar");
        // addAndMakeVisible(sidebar);

        // Instantiate the AdditiveSynth
        firstSynth = new SynthForAdding();
    }

    // (This function is called by the app startup code to create our main component)
    Component* createMainContentComponent()     { return new MainContentComponent(); }

    MainContentComponent::~MainContentComponent()
    {
        delete firstSynth;
        shutdownAudio();
    }

//==============================================================================
// Public Audio Functions

    void MainContentComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
    {
        // (*firstSynth)prepareToPlay(samplesPerBlockExpected, sampleRate);
    }

    void MainContentComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
    {
        // (*firstSynth).getNextAudioBlock(bufferToFill);
    }

    void MainContentComponent::releaseResources()
    {
    }

//==============================================================================
// Public UI Functions

    void MainContentComponent::paint (Graphics& g)
    {
    }

    void MainContentComponent::resized()
    {
        Rectangle<int> currentArea(getLocalBounds());
        area = currentArea;

        // Header
        const int headerFooterHeight = 36;
        header.setBounds (area.removeFromTop (headerFooterHeight));
        footer.setBounds (area.removeFromBottom (headerFooterHeight));

        // Sidebar
        const int sidebarWidth = 80;
        sidebar = (area.removeFromLeft(sidebarWidth));
        Rectangle<int> mainVolumeRectangle(sidebar);
        mainVolumeRectangle.setPosition(mainVolumeRectangle.getX() + 5, mainVolumeRectangle.getY() + (sidebar.getHeight() / 2) - 10);
        mainVolumeRectangle.setSize(mainVolumeRectangle.getWidth() - 10, mainVolumeRectangle.getHeight() / 2);
        mainVolumeSlider.setBounds(mainVolumeRectangle);

        // Main Synth Area
        const int synthHeight = 100;
        Rectangle<int> synthOne(area.removeFromTop(synthHeight));
        // (*firstSynth).setBounds(synthOne);
    }

//==============================================================================
// Slider::Listener Functions

    void MainContentComponent::sliderValueChanged (Slider* slider){
        if (slider == &mainVolumeSlider){
           mainVolumeLevel = mainVolumeSlider.getValue();
        }
    }

//==============================================================================
//==============================================================================
//==============================================================================
// Private Functions
