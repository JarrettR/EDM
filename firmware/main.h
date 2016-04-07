#ifndef	_MAIN_H
#define	_MAIN_H



#ifndef _HTC_H_
#include <htc.h>
#endif


#include "adc.h"
#include "motor.h"
#include "comm.h"
#include "display.h"


#ifndef _XTAL_FREQ
 #define _XTAL_FREQ 8000000
#endif

#define STATE_STARTUP 1
#define STATE_CHARGE 2

#define PIN_CHARGE PORTDbits.RD2
#define PIN_DISCHARGE PORTDbits.RD1

void test_function(int);
void EnableUART(void);
void SendMessage (const char*);


#endif