#include <avr/io.h>
#include <avr/eeprom.h>

#define F_CPU 1000000UL  // 1 MHz
#include <util/delay.h>

// #include "libs/twi_bit_banger/TWI_master.h"

#define PARACHUTE PB5

int main(void) {

	/* Setup */

	DDRB |= _BV(PARACHUTE); // set pin connected to fet transistor as output

	while(1) {
		PORTB |= _BV(PARACHUTE);
		_delay_ms(3000);
		PORTB &= ~_BV(PARACHUTE);
	}

	// Write 8 bit value in EEPROM at adress 0
	/*	
	uint8_t *adress = (uint8_t *) 0;
	uint8_t value = 0;

	for(int i = 0; i < 5; i++) {
		eeprom_update_byte(adress, value);
		_delay_ms(10);
		adress++;
		value++;
	}
	*/

	return(0);
}
