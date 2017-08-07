/*
  ==============================================================================

    BasicAudioProcessorEditor.cpp
    Updated: 08/06/17
    Author:  Brendan Thompson

    A basic user interface that inherits from the AudioProcessorEditor class

  ==============================================================================
*/

#include "BasicAudioProcessorEditor.h"
#include "BasicAudioProcessor.h"

//==============================================================================
// Constructor & Destructor
	BasicAudioProcessorEditor::BasicAudioProcessorEditor(BasicAudioProcessor& owner)
		: AudioProcessorEditor (owner)
	{

	}

	BasicAudioProcessorEditor::~BasicAudioProcessorEditor(){

	}

//==============================================================================
// Public UI Functions

	void BasicAudioProcessorEditor::paint (Graphics& g){

	}

	void BasicAudioProcessorEditor::resized(){

	}

//==============================================================================
// Slider::Listener Functions

	//void BasicAudioProcessorEditor::sliderValueChanged (Slider* slider){
	//     if (slider == &mainVolumeSlider){
	//        MainComponent::volumeChanged(mainVolumeSlider.getValue());
	//     }
	//     if (slider == &frequencySlider){
	//         currentFrequency = frequencySlider.getValue();
	//         if (currentSampleRate > 0.0){
	//             updateAngleDelta();
	//         }
	//     }
	//}
