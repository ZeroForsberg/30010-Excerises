#include "ansi.h"
#include "LCD.h"

uint8_t buffer[512];

void lcdWrite(char slice[], uint8_t line, int32_t place){
	for (int j = 0; j < strlen(slice); j++) {
		int x = slice[j];
		for (int i = 0; i < 5; i++) {
			if (i + place + j * 5 > 127) {
				place = place - 128;
			}
			buffer[i + place + j * 5] = character_data[x - 32][i];

		}
	}

	lcd_push_buffer(buffer);
	memset(buffer, 0x00, place);

}

void lcdScrollText(char slice[], int p){
	lcdWrite(slice, 1, p);
	lcd_push_buffer(buffer);
	memset(buffer, 0x00, p);
}


int lcd_write_string_scroll(char slice[], uint32_t line, uint32_t place) {
	for (int j = 0; j < strlen(slice); j++) {
		int x = slice[j];
		for (int i = 0; i < 5; i++) {
				if (i + place + j * 5 > 127) {
					place = place - 128;
				}

				buffer[i + place + j * 5] = character_data[x - 32][i];
		}
	}
}

int lcd_update_scroll(char n[], int p) {
		lcd_write_string_scroll(n, 1, p);
		lcd_push_buffer(buffer);
		memset(buffer, 0x00, p);

}

void lcd_write_string(char slice[], uint32_t line, uint32_t place) {
	for (int j = 0; j < strlen(slice); j++) {
		int x = slice[j];
		for (int i = 0; i < 5; i++) {
			if (line == 1) {
				buffer[i + place + j * 5] = character_data[x - 32][i];
			}
			if (line == 2) {
				buffer[128 + i + place + j * 5] = character_data[x - 32][i];
			}
			if (line == 3) {
				buffer[256 + i + place + j * 5] = character_data[x - 32][i];
			}
			if (line == 4) {
				buffer[384 + i + place + j * 5] = character_data[x - 32][i];
			}
		}
	}
}




void lcd_update(char n[], int p) {
		lcd_write_string(n, 1, p);
		lcd_push_buffer(buffer);
		memset(buffer, 0x00, p);
}


// lcd_init() // which sets up the SPI port and
// configures the LCD

// lcd_reset() // reboots and reconfigures the LCD and probably won't be of much use to you.

// lcd_transmit_byte() // is used to send data and commands to the display and should only be used if you
// know what you are doing.



// lcd_push_buffer() //transmits a byte array (size of 512) to the LCD and
//shows the data
