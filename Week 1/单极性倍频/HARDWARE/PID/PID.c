#include "PID.h"
#include "adc.h"
#include "delay.h"
#include "oled.h"
#include "timer.h"

extern double dt;
double k;
int n=400,mark=0;

struct _pid{
    double err;     
    double err_last;
	  double err_next;
    double Kp,Ki,Kd;  
    double increment;  
    
}pid;

void PID_init(){
    pid.err=0.0;		//ʵ�����
    pid.err_last=0.0;	//��һ�ε����
    pid.err_next=0.0;	//����ֵ
    pid.Kp=0.6;
    pid.Ki=2.6;//ע�⣬���ϼ�����ȣ�����Ӵ��˻��ֻ��ڵ�ֵ
    pid.Kd=0.0;
}

double PID_realize()
{
	
	pid.err=dt;
	pid.increment=pid.Kp*(pid.err-pid.err_next)+pid.Ki*pid.err+pid.Kd*(pid.err-2*pid.err_next+pid.err_last);
	pid.err_last=pid.err_next;
  pid.err_next=pid.err;
  
	return pid.increment;
}

void PWM_set(double a)
{ 
  k=((a*50)/(float)(30000.0));
	n+=k;
	
  if(n>400){n%=400;}
  if(n<0){n=400-((-n)%400);}
	
}
