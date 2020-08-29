# Carbo-1 - Notes

## Writing to internal EEPROM

```c
	// Write 16 bit value (12345( in EEPROM at adress 5 and 6
	
	eeprom_update_word((uint16_t *) 5, 12345);

	// Write string in EEPROM at adress 16 to 29

	char *stringPointer = (char *) 16;
	char myString[] = "witaj, swiecie";
	eeprom_update_block(myString, stringPointer, sizeof(myString));
```

## Writing to external EEPROM

```c
	unsigned char ret;
    i2c_init();                             // initialize I2C library
    // write 0x75 to EEPROM address 5 (Byte Write)
    i2c_start_wait(Dev24C02+I2C_WRITE);     // set device address and write mode
    i2c_write(0x05);                        // write address = 5
    i2c_write(0x75);                        // write value 0x75 to EEPROM
    i2c_stop();                             // set stop conditon = release bus
    // read previously written value back from EEPROM address 5
    i2c_start_wait(Dev24C02+I2C_WRITE);     // set device address and write mode
    i2c_write(0x05);                        // write address = 5
    i2c_rep_start(Dev24C02+I2C_READ);       // set device address and read mode
    ret = i2c_readNak();                    // read one byte from EEPROM
    i2c_stop();
    for(;;);
```
