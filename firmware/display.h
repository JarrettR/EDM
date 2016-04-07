#ifndef	_DISPLAY_H
#define	_DISPLAY_H


#define DISPLAY_A	PORTDbits.RD7
#define DISPLAY_B	PORTDbits.RD6
#define DISPLAY_C	PORTDbits.RD5
#define DISPLAY_CLK	PORTDbits.RD4

#define DISPLAY_A_TRI	TRISDbits.TRISD7
#define DISPLAY_B_TRI	TRISDbits.TRISD6
#define DISPLAY_C_TRI	TRISDbits.TRISD5
#define DISPLAY_CLK_TRI	TRISDbits.TRISD4

#define DISPLAY_CLK_DELAY	20

void setupDisplay(void);

void setDisplayLevel(int);

void sendDisplay(void);

#endif