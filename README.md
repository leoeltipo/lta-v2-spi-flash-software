# lta-v2-spi-flash-software

Software of the project that allows accessing the platform
flash after boot using SPI block. The software allows read
and write, as well as reading the flash configuration 
structure defined for the lta board.

# Clonning repository to work with Xilinx SDK

* Create a SDK the usual way (Export Hardware and Launch SDK).
* Create an application (Empty app) the usual way.
* Navigate the Git Console to that location, where the src/ directory is.
* git init to start a new empty git repository.
* Register that repo with the remote GitHub repo:
-> git remote add origin https://github.com/leoeltipo/lta-v2-spi-flash-software.git
* git pull origin master
* git push origin master

Now the files are already cloned.

* In Xilinx SDK, right click on project name and Refresh.
* Add inc/ path in project settings.
* That's it. Commit, push and pull the usual way from command line.
