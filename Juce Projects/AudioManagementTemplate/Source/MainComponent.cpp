/*
  ==============================================================================

    MainComponent.cpp
    Updated: 08/06/2017
    Author:  Brendan Thompson

    MainComponent for an Audio Plugin
    Controls the AudioDeviceManager & AudioProcessorGraph

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
// Constructor & Destructor

    MainContentComponent::MainContentComponent()
    {
        setSize (800, 600);
        // specify the number of input and output channels that we want to open
        setAudioChannels (NUMBER_INPUT_CHANNELS, NUMBER_OUTPUT_CHANNELS);

        initialiseAudioProcessingHierarchy();

    }

    MainContentComponent::~MainContentComponent()
    {
        // Shutdown the audio processing class hierarchy
        mainDeviceManager.removeAudioCallback(&mainPlayer);
        shutdownAudio();
    }

    // (This function is called by the app startup code to create our main component)
    Component* createMainContentComponent()     { return new MainContentComponent(); }

//==============================================================================
// Public Audio Functions
    void MainContentComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
    }

    void MainContentComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
    {
        // Your audio-processing code goes here!

        // For more details, see the help for AudioProcessor::getNextAudioBlock()

        // Right now we are not producing any data, in which case we need to clear the buffer
        // (to prevent the output of random noise)
        bufferToFill.clearActiveBufferRegion();
    }

    void MainContentComponent::releaseResources()
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
    }



//==============================================================================
// Public UI Functions
    void MainContentComponent::paint (Graphics& g)
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

        // You can add your drawing code here!
    }

    void MainContentComponent::resized()
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
    }


//==============================================================================
//==============================================================================

//==============================================================================
// Private Initialization Functions

    void MainContentComponent::initialiseAudioProcessingHierarchy(){
        mainDeviceManager.initialiseWithDefaultDevices(NUMBER_INPUT_CHANNELS, NUMBER_OUTPUT_CHANNELS);
        mainDeviceManager.addAudioCallback(&mainPlayer);
        mainPlayer.setProcessor(&mainGraph);

        // The mainAudioGraph
        mainGraph.clear();
        firstProcessor = createPluginFilter();
        AudioProcessorGraph::Node* firstNodePointer = mainGraph.addNode(firstProcessor, BasicAudioProcessor::BASIC_PROCESSOR_ID);
        // AudioProcessorGraph::AudioGraphIOProcessor* in = new AudioProcessorGraph::AudioGraphIOProcessor(AudioProcessorGraph::AudioGraphIOProcessor::audioInputNode);
        // mainInputNode =
        // AudioProcessorGraph::AudioGraphIOProcessor* out = new AudioProcessorGraph::AudioGraphIOProcessor(AudioProcessorGraph::AudioGraphIOProcessor::audioOutputNode);


        //firstProcessor = new BasicAudioProcessor;
        // if (firstNodePointer == nullptr){
        //     // Unable to add the processor node to the mainAudioGraph
        // }
    }



//==============================================================================
// Private Xml Functions
    // XmlElement* MainComponent::createXml(){

    // }