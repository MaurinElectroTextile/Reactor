ElectroTextile
==============
This project is combining ATTiny85 and SOMO-4D (embedded audio-sound module) into an stand alone audio player electronic board made for a knitted fabric sensor.

# ATTiny85 pin mapping

	(PCINT5/RESET/ADC0/dW)		PB5 -	 - vcc
	(PCINT3/XTAL1/CLKI/OC1B/ADC3)	PB3 -	 - PB2 (SCK/USCK/SCL/ADC1/T0/INT0/PCINT2)
	(PCINT4/XTAL2/CLKO/OC1B/ADC2)	PB4 -	 - PB1 (MISO/DO/AIN1/OC0B/OC1A/PCINT1)
					GND -	 - PB0 (MOSI/DI/SDA/AIN0/OC0A/OC1A/AREF/PCINT0)
# SOMO-4D pin mapping

	NEXT - 1	      14 - AUDIO
	  NC - 2 	      13 - NC
	 CLK - 3	      12 - SPK-
	DATA - 4 	      11 - SPK+
	BUSY - 5 	      10 - RESET
   STOP/PLAY - 6	       9 - GND
    PREVIOUS - 7	       8 - VCC

# SOMO-4D commands
 0000h – 01FFh - AUDIO FILE ADDRESS
 FFF0h – FFF7h - VOLUME
 FFFEh - PLAY/PAUSE
 FFFFh - STOP (power idle mode)

- Selecting sample is based on derived sensor value
- The Arduino sketch implement sleep mode to reduce power consumption
The following link present à metod to programe ATTiny with Arduino: http://hlt.media.mit.edu/?p=1229
