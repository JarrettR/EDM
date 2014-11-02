
#ifndef _MAIN_H_
#include "main.h"
#endif

int setupMotor(void) {
	//
	MOTOR_Z_A_TRI = 0;
	MOTOR_Z_B_TRI = 0;
	MOTOR_Z_C_TRI = 0;
	MOTOR_Z_D_TRI = 0;
	
	MOTOR_Z_A = 0;
	MOTOR_Z_B = 0;
	MOTOR_Z_C = 0;
	MOTOR_Z_D = 0;
	
	return 0;
}

int step(int iStep) {
	
	switch(iStep % 8) {
		case 0:
			MOTOR_Z_A = 0;
			MOTOR_Z_B = 0;
			MOTOR_Z_C = 0;
			MOTOR_Z_D = 1;
			break;
		case 1:
			MOTOR_Z_A = 0;
			MOTOR_Z_B = 0;
			MOTOR_Z_C = 1;
			MOTOR_Z_D = 1;
			break;
		case 2:
			MOTOR_Z_A = 0;
			MOTOR_Z_B = 0;
			MOTOR_Z_C = 1;
			MOTOR_Z_D = 0;
			break;
		case 3:
			MOTOR_Z_A = 0;
			MOTOR_Z_B = 1;
			MOTOR_Z_C = 1;
			MOTOR_Z_D = 0;
			break;
		case 4:
			MOTOR_Z_A = 0;
			MOTOR_Z_B = 1;
			MOTOR_Z_C = 0;
			MOTOR_Z_D = 0;
			break;
		case 5:
			MOTOR_Z_A = 1;
			MOTOR_Z_B = 1;
			MOTOR_Z_C = 0;
			MOTOR_Z_D = 0;
			break;
		case 6:
			MOTOR_Z_A = 1;
			MOTOR_Z_B = 0;
			MOTOR_Z_C = 0;
			MOTOR_Z_D = 0;
			break;
		case 7:
			MOTOR_Z_A = 1;
			MOTOR_Z_B = 0;
			MOTOR_Z_C = 0;
			MOTOR_Z_D = 1;
			break;
    }
    
    
	__delay_ms(STEP_DELAY);
		
		
	return 1;
}