scoring_machine
===============

Arduino based fencing scoring machine

###Prerequisites###

Install PlatformIO:

    $ sudo python -c "$(curl -fsSL https://raw.githubusercontent.com/ivankravets/platformio/master/scripts/get-platformio.py)"

This will install the *platformio* command line tool.

###Build###

Run the build:

    $ platformio run
    
Install the build on a connected board:

    $ platformio run --target upload
    
    example: platformio run --upload-port /dev/cu.usbmodem1411 -t upload

###Output###

To view the output from the *Serial.println* statements:

Find out what port the Arduino device is listening on:

    $ platformio serialports list

Listen to the specific port:

    $ platformio serialports monitor -p /dev/cu.usbmodem1411


    
