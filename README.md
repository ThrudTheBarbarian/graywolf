This is graywolf-mac - a fork of graywolf, which in turn is a fork of TimberWolf 6.3.5

The main/only difference between this tree and 
[https://github.com/rubund/graywolf](the original) is that this code will 
compile cleanly on the Mac.

Pre-requisites:
 * Get and install the appropriate version of [http://macports.org](Macports)
	 for your OS
 * type 'sudo port install cmake pkgconfig gsl xorg'
 * Follow the directions below. graywolf ought to build cleanly with no warnings.
 
I personally run the 'RUNME' script at the top level, which sets the $prefix
directory to /opt/asic but this is purely a preference.

--- Original readme follows ---

TimberWolf was developed at Yale University, and was distributed as open source
for a time until it was taken commercial. The last open-source version of
TimberWolf does not perform detail routing, but is a professional-grade
placement tool. In order to continue improving the open-source version,
graywolf has been forked off from version 6.3.5 of TimberWolf.

The main improvement in graywolf is that the build process is more streamlined
and that it behaves as a normal linux tool - you can call it from anywhere and
no environment variables must be set first.

What it does
------------

graywolf is used for placement in VLSI design. It's mainly used together with
qflow.

Install procedure
-----------------

cmake .   
make  
sudo make install  
