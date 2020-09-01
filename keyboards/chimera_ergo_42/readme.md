# Chimera Ergo 42

![Chimera Ergo 42](https://imgur.com/Yasp0s6)

A split wireless 40% ergonomic keyboard 

Keyboard Maintainer: [William Wilson](https://github.com/GlenPickle)  


Hardware Supported: Chimera Ergo PCB, WaveShare core nRF51822

Hardware Availability: [Gerbers](https://github.com/GlenPickle/Chimera/tree/master/ergo/gerbers)

Make example for this keyboard (after setting up your build environment):

    make chimera_ergo_42:default

See [build environment setup](https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.

The keymap is flashed directly to the receiver, not the keyboard itself. If you make any changes to the keymap, they will need to be flashed to the receiver using the same micro USB port that is used to connect it to the computer. In order to put it into bootloader mode, simply press the button labeled "R" on the receiver. To upload a .hex file to the receiver, use the following guide: https://deskthority.net/workshop-f7/how-to-use-a-pro-micro-as-a-cheap-controller-converter-like-soarer-s-t8448.html

how to flash
sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -F -c avr109 -U flash:w:chimera_ergo_42_default.hex
