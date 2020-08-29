MCU=attiny13
F_CPU=1000000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-mmcu=${MCU} -DF_CPU=${F_CPU} \
		-std=c99 -Wall -g -Os -I.	 \
	   	-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
TARGET=carbo_one
SRCS=src/main.c 
#	 libs/twi_bit_banger/TWI_master.c

all:
	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	avrdude -p ${MCU} -c usbasp -U flash:w:${TARGET}.hex:i -F -P usb

clean:
	rm -f *.bin *.hex
