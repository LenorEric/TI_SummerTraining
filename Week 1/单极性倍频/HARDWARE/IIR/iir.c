#include "iir.h" 

  double A[3]={1,-1.9991114234707954,0.99911181807963845};
  double B[3]={1,2,1};
  double Gain=0.000000098652210744415034;
  double w_x[3]={0,0,0};
  double w_y[3]={0,0,0}; 


double IIR_Realize(double input)
{
	double out=0;
	w_x[0] = input;
	w_y[0] = (B[0]*w_x[0] + B[1]*w_x[1] + B[2]*w_x[2])*Gain - A[1]*w_y[1]- A[2]*w_y[2];
	w_x[2] = w_x[1];
	w_x[1] = w_x[0];
	w_y[2] = w_y[1];
	w_y[1] = w_y[0];
	w_y[0]/=A[0];
	out=w_y[0];
	return out;
}




