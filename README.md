# Embedded-C-Testing:

- Implementation of newly created Bash scripts for the RPi4
- Refactoring existing test scripts (work)
- Need to create and update the make files to run in unity
- Note* Code and exercises are pulled from the Test-Driven Development 
for Embedded C book. See "Rights file".
- Need to update makefiles...
- Initialized circular buffer test, working out the workflow diagram
- Added some bash scripting for practice
- Learning about using pipes in functions for bash
- Reading and writing files using redirection in bash
- 

Bash Scripting:

- Using pipes in functions
- Reading and writing files using redirection
- Using the sleep command and how to put scripts to sleep
- Watching procs with scripts
- Getting input from the user and validating the input
- How to create a simple guessing game in Bash
- 

Docker Setup:

- To Run: docker run -it --rm <...>
- To point to the same path as filesystem: docker run -it --rm -v $PWD:/...

Command shortlist:

- ceedling test:all
- when compiling using gstreamer libraries: 
pkg-config --cflags --libs gstreamer-1.0

Updates:

- Initial commit for Client-Server app on Rpi4                          08052021
- Creating Test branch from Master (trl_testing)                        07262021
- Updated source files in trl_testing for feature addition              07252021
- Added template for user proc .c/.h in trl_testing                     07092021
- Start looking into SystemTap implementation in the kernel             07072021
- Started course: UAMx ProgC01                                          07032021
- See "Google Test Projects Updates"                                    06302021
- Migrating GTest items to private repo for testing production code     06232021
- Cleaning up unused portions in this EC2 instance                      06162021
- Nearing completion                                                    06082021
- Implementation of Employee DB Mngr. Project in progress               06032021
- GMock preparation for Employee Database Manager Project               05312021
- Linked Google Mock in local VS project                                05292021
- Started running initial sample tests -> beggining class tests next    05232021 
- Initial switch to unit testing using Google C++ Testing Framework     05212021
- Started unit testing trl - try another function                       05172021
- Count variable is not incrementing Shell Script v.1.2 (Private)       05052021 
- Update Shell Script v.1.2 to fix "no log dump w/o connection to host" 04282021
- Restructure CW_10mw test putting on hold due to other priorites       05212021 
- Updated Network Bash Shell Scripts v.1.2 (Private)                    04072021
- Updated Network Bash Shell Scripts v.1.1 (Private)                    03072021
- Moving unto more network testing using the Socket API (C)
- Updated Network Bash Shell Scripts v.1.0 (Private)                    02062021
- Implementation of RPi4 Reflex v.0 - TDD approach using Unity.
- Swithing projects = Reflex input using wiringPi library and 10-minute walk
- (Udemy Course) Working on iteration 1 - 
- Second Feature "Let's get digital -14.09:30 
- Need to fix the test buld, I don't know why it's broken... 
- docker run -it --rm -v $PWD:/lab throwtheswitch/drsurly-course2
- Migrated repository 10-10-2020

Google Test Projects Updates:
- Initial setup and commit for simple Google Test Projects - 06282021
