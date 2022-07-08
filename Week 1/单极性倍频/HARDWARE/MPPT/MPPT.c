#include "MPPT.h"
#include "adc.h"
#include "delay.h"
#include "timer.h"

double uk,un;
extern double K;

struct _mppt{
    double U_now,U_last;    
    double I;
	  double P_err,U_err;
    double P_now,P_last;  
    double U_deltaout; 
    double U_step;
	  double U_out;
    double P_err_min;	
	  double U_err_min;
    
}mppt;

void MPPT_init(){
    mppt.U_now=0.0;	
    mppt.U_last=0.0;
    mppt.I=0.0;	
    mppt.P_now=0.0;	
    mppt.P_last=0.0;
    mppt.P_err=0.0;
	  mppt.U_err=0.0;
    mppt.U_out=0.0;
	  mppt.U_step=0.1;//步长
	  mppt.P_err_min=0.01;//分辨值
	  mppt.U_err_min=0.02;//分辨值
}

double MPPT_realize()
{
  mppt.U_now=(Get_Adc_Average(9,2)-Get_Adc_Average(8,2))*3.3/(double)4096.0;
	mppt.I=(Get_Adc_Average(14,2))*3.3/(double)4096.0;
	mppt.P_now=mppt.U_now*mppt.I;
	mppt.P_err=mppt.P_now-mppt.P_last;
	
	if(mppt.P_err>mppt.P_err_min)
	{     
		mppt.U_err=mppt.U_now-mppt.U_last;
	   if(mppt.U_err>mppt.U_err_min)
			 {
		     mppt.U_out =mppt.U_now +mppt.U_step;
		 }
		 else{
		     mppt.U_out =mppt.U_now -mppt.U_step;
	   }}
	else{
	   mppt.U_err=mppt.U_last-mppt.U_now;
	    if(mppt.U_err>mppt.U_err_min)
			 {
		     mppt.U_out =mppt.U_now -mppt.U_step;
		 }
		 else{
		     mppt.U_out =mppt.U_now +mppt.U_step;
	   }
	}
	mppt.U_last=mppt.U_now;
  mppt.P_last=mppt.P_now;

	return mppt.U_out;
}

void MPPT_set(double a)
{
	un=(Get_Adc_Average(9,2)-Get_Adc_Average(8,2))*3.3/(double)4096.0;
  uk=a/(double)(un);//mppt计算出的电压与目前电压的比值
	if(uk>0&&uk<1){K=uk;}
}
