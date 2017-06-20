# VST-Project

Brendan Thompson
README.md
06/19/17

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

			- Current Status - 06/19/17 ---
			
- It has been a slow and laborious process getting my first plugin to build and be ran
- After trying WDL-OL for 3 days I have switched to trying JUCE

------------------------------------------------------------------------------
------------------------------------------------------------------------------

			- The Development Logs ---
			
There are a few reasons that I am creating this detailed log:
1) I want to make some awesome custom synths that my friends and I can use in music production
2) The information will be here for me to look back at it in the future if I run into similar problems or need to repeat any processes
3) It helps me keep all of these webpages and other sources of information organized and available
4) Maybe someday someone will use this to guide them through VST Plugin creation 
5) Possibly by publishing this online other people dealing with some of these same issues can possibly learn from my experience
6) I hope that it may both strengthen and demonstrate my ability to learn advanced topics, solve all sorts of problems, stay motivated, get excited, and produce beautiful programs.

------------------------------------------------------------------------------
------------------------------------------------------------------------------	
		
			- Software Choices ---
			
- Why I Switched to JUCE ---
	- Hopefully up to date and compatible with modern computers
	- Well developed and maintained by a legitimate company
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
		- All of the content in the files are radically different
		- The folders are totally different and have different files
	4) EVERYTHING is old and outdated
 
- Why I Originally Chose WDL-OL ---
	1) It relies heavily on just code and very little on virtual hardware or pre-coded modules. 
	2) It involves using Microsoft Visual Studio, which is software that I need to start getting acquanted with. 
	3) There is an in depth tutorial for the method online at http://www.martin-finke.de/blog/articles/audio-plugins-001-introduction/

------------------------------------------------------------------------------
------------------------------------------------------------------------------
------------------------------------------------------------------------------