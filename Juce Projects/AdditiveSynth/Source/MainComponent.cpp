/*
  ==============================================================================

    MainComponent.cpp
    Updated: 31 Jul 2017
    Author:  Brendan Thompson

    Main Audio Processor for the Additive Synthesizer

  ==============================================================================
*/

#include "MainComponent.h"
#include "MainAudioProcessor.h"

//==============================================================================
// Constructor & Destructor

    MainContentComponent::MainContentComponent()
    {
        setSize (800, 600);
        // specify the number of input and output channels that we want to open
        setAudioChannels (0, 4);
        //return new MainAudioProcessor();
    }

    MainContentComponent::~MainContentComponent()
    {
        shutdownAudio();
    }

//==============================================================================
// Public Audio Functions

    void MainContentComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
    {
    }

    void MainContentComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
    {
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
    }

//==============================================================================
// Slider::Listener Functions

    void MainContentComponent::sliderValueChanged (Slider* slider){
    }



//==============================================================================
//==============================================================================
//==============================================================================
// Private Functions
    
//==============================================================================
// (This function is called by the app startup code to create our main component)
    Component* createMainContentComponent()     { return new MainContentComponent(); }
    AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new MainAudioProcessor(); }