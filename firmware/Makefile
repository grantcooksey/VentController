SKETCH=sketch
BOARD_TYPE=ATTinyCore:avr:attinyx5
# Apparently using 1internal is faster than the default 8internal clock. The timing was all off using that option, idk???
# ATTinyCore:avr - 1.5.2
BOARD_OPTIONS=clock=1internal
# ATTinyCore:avr - 2.0.0
# BOARD_OPTIONS=clock=internal_1m
FQBN=$(BOARD_TYPE):$(BOARD_OPTIONS)
BUILD_DIR=build

.PHONY: all compile upload

all: compile upload

compile:
	arduino-cli compile --fqbn $(FQBN) --build-path $(BUILD_DIR) $(SKETCH)

# Programmer name from https://github.com/arduino/ArduinoCore-avr/blob/master/programmers.txt
# Using the USPtinyISP stick here. Apparently ISP's don't support serial ports.
#
# Sometimes the bitclock doesn't get set right for this command. If seeing the rc=1 error, make sure the flag -B8 is set
# You may need to manually set the avrdude command.
upload:
	arduino-cli upload --fqbn $(FQBN) --programmer usbtinyisp --input-dir $(BUILD_DIR) -v $(SKETCH)

details:
	arduino-cli board details --fqbn $(BOARD_TYPE)