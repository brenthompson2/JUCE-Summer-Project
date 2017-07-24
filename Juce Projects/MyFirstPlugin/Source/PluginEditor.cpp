/*  Brendan Thompson
*   PluginEditor.cpp
*   07/23/17
*
*  ==============================================================================
*
*   This file was auto-generated!
*
*   It contains the basic framework code for a JUCE plugin editor.
*
* ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MyFirstPluginAudioProcessorEditor::MyFirstPluginAudioProcessorEditor (MyFirstPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 300);
}

MyFirstPluginAudioProcessorEditor::~MyFirstPluginAudioProcessorEditor()
{
}

//==============================================================================
void MyFirstPluginAudioProcessorEditor::paint (Graphics& g)
{
}

void MyFirstPluginAudioProcessorEditor::resized()
{
}
