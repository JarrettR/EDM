
#ifndef _MAIN_H_
#include "main.h"
#endif

char display_chip_a = 0;
char display_chip_b = 0;
char display_chip_c = 0;

void setupDisplay() {
	
	DISPLAY_A_TRI = 0;
	DISPLAY_B_TRI = 0;
	DISPLAY_C_TRI = 0;
	DISPLAY_CLK_TRI = 0;
	return;
}

void setDisplayLevel(int iLevel) {
	int iCode;
	
	//Todo: change this to lookup table
	switch(iLevel % 11) {
		case 0:
			iCode = ~0;
			break;
		case 1:
			iCode = ~0x01;
			break;
		case 2:
			iCode = ~0x03;
			break;
		case 3:
			iCode = ~0x07;
			break;
		case 4:
			iCode = ~0x0f;
			break;
		case 5:
			iCode = ~0x1f;
			break;
		case 6:
			iCode = ~0x3f;
			break;
		case 7:
			iCode = ~0x7f;
			break;
		case 8:
			iCode = ~0xff;
			break;
		case 9:
			iCode = ~0x01ff;
			break;
		case 10:
			iCode = ~0x03ff;
			break;
	}
	
	
	
	display_chip_a = (char)(iCode >> 0) & 0xFF;
	
	display_chip_b = display_chip_b & 0xFE; //Clear LSB
	display_chip_b = display_chip_b | ((char)(iCode >> 8) & 0x01);  //Set bit
	
	display_chip_c = display_chip_c & 0xFE;
	display_chip_c = display_chip_c | ((char)(iCode >> 9) & 0x01);  //Set bit
	
	return;
}

void sendDisplay() {
	
	for(int i = 0; i <= 7; i++) {
		DISPLAY_A = (display_chip_a >> i) & 0x01;
		DISPLAY_B = (display_chip_b >> i) & 0x01;
		DISPLAY_C = (display_chip_c >> i) & 0x01;
		
		DISPLAY_CLK = 0;
		__delay_us(DISPLAY_CLK_DELAY);
		
		DISPLAY_CLK = 1;
		__delay_us(DISPLAY_CLK_DELAY);
		
	}
	return;
}
	