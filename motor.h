#ifndef	_MOTOR_H
#define	_MOTOR_H


#define	MOTOR_Z_A PORTCbits.RC7
#define	MOTOR_Z_B PORTCbits.RC6
#define	MOTOR_Z_C PORTCbits.RC5
#define	MOTOR_Z_D PORTCbits.RC4

#define	MOTOR_Z_A_TRI TRISCbits.TRISC7
#define	MOTOR_Z_B_TRI TRISCbits.TRISC6
#define	MOTOR_Z_C_TRI TRISCbits.TRISC5
#define	MOTOR_Z_D_TRI TRISCbits.TRISC4

#define STEP_DELAY 10

int setupMotor(void);
int step(int);



#endif