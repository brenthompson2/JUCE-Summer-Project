// /*
//   ==============================================================================

//     MainAudioProcessor.cpp
//     Created: 28 Jul 2017 5:50:50pm
//     Author:  Brendan Thompson

//   ==============================================================================
// */

// #include "MainAudioProcessor.h"


// //==============================================================================
// // Constructor & Destructor

//     MainAudioProcessor::MainAudioProcessor()
//     :
//         currentSampleRate (0.0),
//         currentAngle(0.0),
//         angleDelta(0.0),
//         parameters (*this, nullptr)
//     {

//         // Set up the Value Tree for the parameters
//         parameters.createAndAddParameter("volumeLevel", // ID such as a variable name
//                                         "Volume",       // name for display
//                                         String(),       // label for suffix (dB, Hz)
//                                         NormalisableRange<float> (0.0f, MAX_VOLUME),
//                                         0.25,           // default value
//                                         nullptr, nullptr);
//         parameters.createAndAddParameter("currentFrequency",
//                                         "Frequency",
//                                         String(),
//                                         NormalisableRange<float> (MIN_FREQUENCY, MAX_FREQUENCY),
//                                         500.0f,
//                                         nullptr, nullptr);
//         parameters.state = ValueTree (Identifier ("AdditiveSynth"));
//     }

//     MainAudioProcessor::~MainAudioProcessor()
//     {
//     }

// //==============================================================================
// // Public Audio Functions

//     void MainAudioProcessor::prepareToPlay (double sampleRate, int maximumExpectedSamplesPerBlock)
//     {
//         currentSampleRate = sampleRate;
//         updateAngleDelta();
//     }

// 	void MainAudioProcessor::processBlock (AudioBuffer<float> &buffer, MidiBuffer &midiMessages)
//     {
//         const int numChannels = buffer.getNumChannels();
//         const int numSamples = buffer.getNumSamples();
//         for (int channel = 0; channel < numChannels; channel++){
//             float* const tempBuffer = buffer.getWritePointer (channel);
//             for (int sample; sample < numSamples; sample++){
//                 volumeLevel = *parameters.getRawParameterValue("volumeLevel");
//                 // nextSample = (randomGen.nextFloat() * 2.0f - 1.0f); // For Randomly generated White Noise
//                 nextSample = (float) std::sin (currentAngle);
//                 currentAngle += angleDelta;
//                 tempBuffer[sample] = nextSample * volumeLevel;
//             }
//         }
//     }

//     void MainAudioProcessor::releaseResources()
//     {
//     }

// //==============================================================================
// //==============================================================================
// //==============================================================================
// // Private Functions

//     // updateAngleDelta
//     void MainAudioProcessor::updateAngleDelta(){
//         // number of cycles necessary per each output sample, multiplied by length of sine wave cycle (2pi radians)
//         const double cyclesPerSample = currentFrequency / currentSampleRate;
//         angleDelta = cyclesPerSample * 2.0 * double_Pi;
//     }