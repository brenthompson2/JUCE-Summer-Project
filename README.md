# VST-Project

Brendan Thompson
README.md
10/19/17

------------------------------------------------------------------------------
------------------------------------------------------------------------------
------------------------------------------------------------------------------

# Overview
			
For the summer of 2017 I wanted to look into developing a software synthesizer, possibly one that could be loaded as a VST plugin into music production software such as a Digital Audio Workstation (DAW). I decided to use JUICE for a few reasons, mainly becuase it focuses on code as opposed to virtual hardware and it appeared to have a pretty legitimate and large user base. However, attempting to get further into the nuts and bolts passed the tutorials quickly became quite challenging. In the end I gained a much better understanding of C++, gained a huge appreciation for how elaborate Audio software is, realized how complicated Synthesizers are, and created some neat applications. The last one I was able to do before school starting back up was an Additive Synthesizer with automatically Harmonized, yet toggle-able, harmonics.

Check out the Development Logs and take a look as I tought myself the advanced topics necessary, 
laugh as I struggle through the nitty-gritty of troubleshooting EVERYTHING, 
and follow along as the software development process unraveled. 

As quickly as it came the summer ended, leaving me with a million more questions than answers. However, it also left me super hungry. I had an absolute blast teaching myself about audio programming, and can most definitely see myself loving to do it for the rest of my life. Between School, Work, my Internship at Awesome Inc, Lacrosse, my German Shepherd Puppy, and everything else going on in my life I am currently unable to get back into it, but I am really looking forward to the day I finally can. As I purchased my textbooks for the semester I also went ahead and bought "Designing Software Synthesizer Plug-Ins in C++: For RackAFX, VST3, and Audio Units" by Will Pirkle, which should be a really good guide for when the time comes for me to get back into it.


------------------------------------------------------------------------------
------------------------------------------------------------------------------

# Projects
			
- Chord Machine:
	- Barely got started
	- Planned to Automatically play harmonic triads (major, minor, etc)
	- List of Oscillator objects added together
	- Split into multiple files for Oscillators, Interface, etc
	- Toggle On/Off as well as control Volume & Frequency for each Oscillator
	- Control Main Volume
			
- Harmonic Synthesizer:
	- List of Oscillator objects added together
	- Split into multiple files for Oscillators, Interface, etc
	- Automatically tunes subsequent oscillators to match the fundamental
	- Toggle On/Off as well as control Volume & Frequency for each Oscillator
	- Control Main Volume
			
- Additive Synthesizer:
	- List of Oscillator objects added together
	- Split into multiple files for Oscillators, Interface, etc
	- Toggle On/Off as well as control Volume & Frequency for each Oscillator
	- Control Main Volume
			
- Additive Manual:
	- Hardcoded a List of Oscillators and added them together
	- Interface & Processor in same files
	- Toggle On/Off as well as control Volume & Frequency for each Oscillator
	- Control Main Volume

- HandlingMidi: 
	- Began attempting to handle midi signals
	- Never tested with an actual MIDI controller
	
- AudioManagementTemplate:
	- Where most of my time and energy got wasted
	- Attemted to use the elaborate juce classes to handle the flow of audio
	- See "Current Standing" of this blog post: https://brenthompson2.github.io/JUCE-Intro

- FirstSynth: 
	- One oscillator
	- Decent layout of the Interface
	- Controls for Volume & Frequency of that oscillator
	
- MyFirstPlugin: 
	- Blank Audio Plugin project
	- should be able to open it in a DAW but never tested

- Tutorial6TAP: 
	- Followed along with a youtube tutorial creating and customizing sliders
	
------------------------------------------------------------------------------
------------------------------------------------------------------------------

# Development Logs
			
There are a few reasons that I created the detailed logs:
	- It serves as a guide in case I ever need to redo any of the processes
	- It is a notebook to review and reference while producing audio software
	- There are summaries of research such as articles, tutorials, and videos that I can always reference
	- Hopefully others may use this to guide their own research into Audio Plugin creation 
	- As a demonstration of my current ability and potential to grow

------------------------------------------------------------------------------
------------------------------------------------------------------------------
------------------------------------------------------------------------------
