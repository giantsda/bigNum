// Solve the PRISM-PY equations for the HSC model.
#include <stdio.h>
#include <math.h>
#include <gmp.h>


// # define PI 3.141592653589793
// # define QPI 12.56637061435917 //Pi*4
// # define ETA 0.445058959258554   //0.85*pi/6.0
// # define DPI2 0.050660591821169 // 1/2/pi/pi
 
 

double e0, e1, e2, e3, e4, e5, e6;
double chat_ana(double q);

int main()
{
  	mpf_set_default_prec(640);
	mpf_t sum,e0,e1,e2,e3,e4,e5,e6,PI,ETA,QPI,DPI2,C,OneMETA,twoPETA,temp,q;
 	mpf_init (sum);	
	mpf_init (e0);	
	mpf_init (e1);	
	mpf_init (e2);	
	mpf_init (e3);	
	mpf_init (e4);	
	mpf_init (e5);	
	mpf_init (e6);	
	mpf_init (PI);	
	mpf_init (ETA);	
	mpf_init (QPI);
	mpf_init (DPI2);
	mpf_init (C); // 0.85/6
	mpf_init (OneMETA); // 1-ETA
	mpf_init (twoPETA); // 2+ETA
	mpf_init (temp); 
	mpf_init (q); 

	mpf_set_str(PI, "3.1415926535897932384626433832795028841971693993751058209749445923078\
		164062862089986280348253421170679821480865132823066470938446095505822317253594081284811\
		174502841027019385211055596446229489549303819644288109756659334461284756482337867831652\
		7120190914564856692346034861", 10);
	mpf_set_str(C, "0.1416666666666666666666666666666666666666666666666666666666\
		66666666666666666666666666666666666666666666666666\
		6666666666666666666666666666666666666666666666666666666666", 10);
	//e0
	mpf_mul_ui(QPI,PI,4);
	mpf_mul (ETA,PI,C); 
	mpf_ui_sub (OneMETA,1,ETA);
	mpf_add_ui (twoPETA,ETA,2);
	mpf_mul(temp,OneMETA,OneMETA);
	mpf_mul(e0,temp,twoPETA);
	//e1
	mpf_mul(temp,ETA,ETA);
	mpf_mul_ui(temp,temp,5);
	mpf_ui_sub (temp,6,temp);
	mpf_mul(temp,ETA,temp);
	mpf_ui_sub (temp,1,temp);
	mpf_mul_ui(e1,PI,-2);
	//e2
	mpf_mul_ui(temp,ETA,7);
	mpf_add_ui (temp,temp,4);
	mpf_mul(temp,ETA,temp);
	mpf_ui_sub (temp,2,temp);
	mpf_mul_ui(e1,PI,6);
	//e3
	mpf_mul(temp,twoPETA,twoPETA);
	mpf_mul(temp,ETA,temp);
	mpf_mul_ui(e1,PI,-6);
	//e4
	mpf_mul_ui (temp,ETA,2);
	mpf_add_ui (temp,temp,1);
	mpf_mul(temp,temp,temp);
	mpf_mul(temp,temp,ETA);
	mpf_mul_ui (temp,temp,24);
	//e5
	mpf_set(e5,e4);
	//e6
	mpf_mul_ui(e6,e5,-1);
	// e0 = (1-ETA)*(1-ETA) * (2+ETA);
	// e1 = -2 * (1-ETA*(6-5*ETA*ETA));
	// e2 = 6*ETA * (2-ETA*(4+7*ETA));
	// e3 = -6*ETA * (2+ETA)*(2+ETA);
	// e4 = e5 = e6 = 24*ETA * (1+2*ETA)*(1+2*ETA);
	// e6 = -e6;
	
	//q
	mpf_div_ui(q,PI,1000);
 
	mpf_set_str(sum, "1.0", 10);
	gmp_printf("%10.100Ff\n",q);
	 


	return (0);
}


double chat_ana(mpf_t q,mpf_t e1, mpf_t e2, mpf_t e3, mpf_t e4, mpf_t e5, mpf_t e6, PI)
{
	int i, j,minIndex;
	mpf_set_default_prec(640);
	mpf_t q2, q3, sinq, cosq, sum,temp,t0,t1,t2,t3,t4,t5,t6;
	mpf_init (q2);	
	mpf_init (q3);	
	mpf_init (sinq);	
	mpf_init (cosq);	
	mpf_init (sum);	
	mpf_init (temp);	
	mpf_init (t0);	
	mpf_init (t1);	
	mpf_init (t2);	
	mpf_init (t3);	
	mpf_init (t4);	
	mpf_init (t5);	
	mpf_init (t6);	
	mpf_mul(q2,q,q);
	mpf_mul(q3,q2,q);




	mpf_mul_ui(temp,ETA,7);
	mpf_add_ui (temp,temp,4);
	mpf_mul(temp,ETA,temp);
	mpf_ui_sub (temp,2,temp);
	mpf_mul_ui(e1,PI,6);



		q2=q*q;  q3=q*q2;  sinq=sin(q);  cosq=cos(q);
		t[0] = e0 * q2 *q2* cosq;
		t[1] = e1 * q3 * sinq;
		t[2] = e2 * q2 * cosq;
		t[3] = e3 * q2;
		t[4] = e4 * q * sinq;
		t[5] = e5 * cosq;
		t[6] = e6;




	if (q==0)  return (PI*(ETA-4)*(2+ETA*ETA) / (6*pow((1-ETA)*(1-ETA),2)));
	else
	{	
		q2=q*q;  q3=q*q2;  sinq=sin(q);  cosq=cos(q);
		t[0] = e0 * q2 *q2* cosq;
		t[1] = e1 * q3 * sinq;
		t[2] = e2 * q2 * cosq;
		t[3] = e3 * q2;
		t[4] = e4 * q * sinq;
		t[5] = e5 * cosq;
		t[6] = e6;
		for ( i = 0; i < 7 - 1; i++) 
		{
			minIndex = i;
			for ( j = i + 1; j < 7; j++) 
			{
				if (fabs(t[j]) < fabs(t[minIndex])) 
				{     // find smallest
					minIndex = j;                 // store smalles index
				}
			}
			temp = t[i];
			t[i] = t[minIndex];
			t[minIndex] = temp;
		}
 
		sum=0.;
		for (i=0;i<7;i++)
			sum=sum+t[i];
				 
		return (2*PI*sum / pow((1-ETA)*(1-ETA)*q3,2));
	}
}
 
