# VST-Project

Brendan Thompson
README.md
07/17/17

------------------------------------------------------------------------------
------------------------------------------------------------------------------
------------------------------------------------------------------------------

			- Overview ---
			
For the summer of 2017 I am attempting to create a VST plug-in synthesizer 
that can be loaded into music production software. 
Follow along in the Development Logs as I teach myself the advanced topics necessary, 
laugh as I struggle through the nitty-gritty of troubleshooting EVERYTHING, 
and watch as my software designing process unravels. 
For a better description of what I intend to create, some of the most popular 
VSTs include both MASSIVE and Reaktor, both of which are by Native Instruments, 
and also Serum which is by Xfer Records.

------------------------------------------------------------------------------
------------------------------------------------------------------------------

			- Current Status - 07/17/17 ---
			
- It has been a slow and laborious process attempting to get my first plugin to build and run
- After trying WDL-OL for 3 days I have switched to trying JUCE
- Currently I am unable to get an add-on from WDL-OL or JUCE to compile on Visual Studio 2017 on my Windows 10 partition
- I am going to attempt to use the VS2015 toolkit and/or possibly attempt to use JUCE on my linux partition and use gcc to compile it
- I have been doing a lot of research into coding with JUCE

------------------------------------------------------------------------------
------------------------------------------------------------------------------

			- The Development Logs ---
			
There are a few reasons that I am creating these detailed log:
	- It serves as a guide in case I ever need to redo any of the processes
	- It is a notebook to review and reference while producing audio software
	- There are summaries of research such as articles, tutorials, and videos that I can always reference
	- Hopefully others may use this to guide their own research into Audio Plugin creation 
	- As a demonstration of my current ability and potential to grow

------------------------------------------------------------------------------
------------------------------------------------------------------------------	
		
			- Software Choices ---
			
- Why I Switched to JUCE ---
	- Hopefully up to date and compatible with modern computers
	- Well developed and maintained by a legitimate company
	- Used by professionals to produce popular legitimate software
	- Online resources like forums and videos
	- Advanced Libraries and Classes
		- JUCE handles most Digital & Audio Signal Processing
		- JUCE handles MIDI input & output
	- Neat GUI development tools
	- Well constructed development software
	- Still C++ coding practice
	- Still practice using other libraries and classes
	- Still uses Visual Studio to build the project

- Main Issues with WDL-OL ---
	1) There are very limited resources for learning this method (approximately 3 total)
	2) Can't Get Visual Studio to run MyFirstPlugin
		- 2 Builds completed but there is still 1 failing
		- "LNK2019 unresolved external symbol "int_stdcall MainDlgProc(struct HWND_*, unsigned int, unsigned int, long)""
		- I am afraid it will take to long to track down that line in the code and attempt to figure out what it is doing
		- Everything being outdated and nothing working is annoying me
		- Tracking down all of these SDKs and Dependencies is a struggle
	3) Can't turn Basic Visual Studio Project into WLD-OL example plugin project
		- All of the content in those files is totally different
		- The folder / file structure is totally different
	4) EVERYTHING is old and outdated
 
- Why I Originally Chose WDL-OL ---
	1) It relies heavily on just code and very little on virtual hardware or pre-coded modules.
		- So does JUCE
	2) It involves using Microsoft Visual Studio, which is software that I need to start getting acquanted with.
		- So does JUCE
	3) There is an in depth tutorial for the method online at http://www.martin-finke.de/blog/articles/audio-plugins-001-introduction/
		- JUCE has a lot more than just 1 tutorial
		
------------------------------------------------------------------------------
------------------------------------------------------------------------------
------------------------------------------------------------------------------
