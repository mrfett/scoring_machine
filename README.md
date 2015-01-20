scoring_machine
===============

Arduino based fencing scoring machine

###Prerequisites###

Install PlatformIO:

    sudo python -c "$(curl -fsSL https://raw.githubusercontent.com/ivankravets/platformio/master/scripts/get-platformio.py)"

This will install the *platformio* command line tool.

###Build###

Run the build:

    platformio run
    
Install the build on a connected board:

    platformio run --target upload
