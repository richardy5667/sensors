#!/bin/bash
stty -F /dev/ttyACM0 1200 hupcl; sleep 2
./bossac -i -d --port=ttyACM0 -U true -e -w -v -b ./firmware.ino.bin -R
