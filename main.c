
#ifndef _MAIN_H_
#include "main.h"
#endif


int state = STATE_STARTUP;
//Int osc, wdt, mclr disabled, bor, fscm
//__CONFIG(0x3b1c);

//FOSC = b100;

//S, M, H
//__EEPROM_DATA(30, 0, 0, 0, 0, 0, 0, 0);	//Default 30s, 0m, 0h


        //PCON = 0xFF;	//Internal osc
	//OPTION_REG = 0x7F; //Internal pullup enable
void EnableUART  ( void )
{
	TRISCbits.TRISC6   = 1;
	SPBRG 			   = 51; //BR = 9600
	TXSTAbits.TXEN 	   = 0;
	TXSTAbits.BRGH 	   = 1;
	RCSTAbits.SPEN 	   = 1;
	
	BAUDCTLbits.BRG16  = 0;		

	TXSTAbits.SYNC 	   = 0;		
	TXSTAbits.TX9  	   = 0;
	INTCONbits.GIE 	   = 0; 	//Disable interrupts
	TXSTAbits.TXEN 	   = 0;
	TXSTAbits.TXEN 	   = 1;
}
	
void SendMessage ( const char* Msg )
{
	while(*Msg)
	{
		TXREG = *Msg++;
		while( !PIR1bits.TXIF );
		//Msg++;
	}
	
	TXREG = '\n'; 
}
void main(void)
{


	//8MHz internal oscillator
	OSCCONbits.IRCF2 = 1;
	OSCCONbits.IRCF1 = 1;
	OSCCONbits.IRCF0 = 1;

	EnableUART();

	//State: setup
	//step();
	//TRISD = 0x00;
	PIN_CHARGE = 0;
	PIN_DISCHARGE = 0; 
	
	setupDisplay();
	setupMotor();
	
	char i = 0;
	
	while(1) {
		step(i);
				
		setDisplayLevel(i);
		sendDisplay();
		
		for(int a = 0; a < 1; a++)
			__delay_ms(10);
		
		i++;
		
	}	


	state = STATE_CHARGE;
}

void test_function(int iOn) {
	//const char what[] = "WHAT";
	//SendMessage(what);
	
	//Set bit
	PORTDbits.RD7 = iOn;
	
	//Clock once
	__delay_ms(10);
	PORTDbits.RD4 = 1;
	__delay_ms(10);
	PORTDbits.RD4 = 0;
	
}	