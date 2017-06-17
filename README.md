# VST-Project

Brendan Thompson
README.md
06/16/17

- Overview ---
	For the summer of 2017 I am attempting to create a VST plug-in synthesizer that can be loaded into music production software. Follow along in the DevLog.txt file as I teach myself the advanced topics necessary, laugh as I struggle through the nitty-gritty of troubleshooting EVERYTHING, and watch as my software designing process unravels. For a better description of what I intend to create, some of the most popular VSTs include both MASSIVE and Reaktor, both of which are by Native Instruments, and also Serum which is by Xfer Records.


- Why I Chose (WDL-OL / IPlug / Visual Basic / Python) ---
	I looked through a few different methods for creating VST Plug-Ins, such as synthedit, JUICE, and MaxMSP, but ended up deciding to use Oli Larkin's WDL-OL library and the IPlug class. I chose this method for a few reasons. First of all, it relies much more on code and very little on virtual hardware or pre-coded modules. Secondly, it involves using Microsoft Visual Studio, which is software that I need to start getting acquanted with. Also, there is an in depth tutorial for this method online at http://www.martin-finke.de/blog/articles/audio-plugins-001-introduction/ . I am not yet sure where the python comes in. I hope that its sole purpose wasn't only just to run Oli-Larkin's duplicate.py script that I had to fix but still didn't rename things properly (See DevLog 06/16/17).
	
- The Development Log ---
	I have been writing extensively in DevLog.txt: taking notes on the different topics, describing just about every issue faced, and documenting pretty much all of the decisions made. There are a few reasons that I am creating this detailed log. First of all, I can always look back at it in the future if I run into problems or need to repeat any of the steps. Secondly, it helps me keep all of these webpages and other sources of information organized and available. Third, I hope that by publishing this online other people dealing with some of these issues I face can possibly learn from what I documented. Fourth, possibly this could be used instead of or alongside martin-finke's article as a more updated version of VST design. Finally, I hope that it may both strengthen and demonstrate my ability to learn advanced topics, solve all sorts of problems, stay motivated, get excited, and produce beautiful programs.

- Current Status - 06/16/17 - 6:45pm ---
	It has been a slow and laborious process getting started. I am on the second/third page of the Martin Finke article. I downloaded all the software, added all of the dependencies, duplicated an old template PlugIn to instantiate MyFirstPlugin, and started analyzing the code. However, I have not yet been able to Open MyFirstPlugin.sln using Visual Studio. I was once able to open Visual Studio in general, but am no longer able to. My plan going forward is to keep analyzing code and when I get internet again I will attempt to uninstall and reinstall Visual Studio. 