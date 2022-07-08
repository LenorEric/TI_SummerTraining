#ifndef _PID_H
#define _PID_H

void PID_init(void);
double PID_realize(void);
void PWM_set(double);

#endif
