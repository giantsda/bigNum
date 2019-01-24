// Solve the PRISM-PY equations for the HSC model.

#include <stdio.h>
#include <math.h>

# define PI 3.141592653589793
# define QPI 12.56637061435917
# define ETA 0.445058959258554
# define DPI2 0.050660591821169
 
 double e0, e1, e2, e3, e4, e5, e6;
double chat_ana(double q);

int main()
{
 
	 
  	e0 = (1-ETA)*(1-ETA) * (2+ETA);
	e1 = -2 * (1-ETA*(6-5*ETA*ETA));
	e2 = 6*ETA * (2-ETA*(4+7*ETA));
	e3 = -6*ETA * (2+ETA)*(2+ETA);
	e4 = e5 = e6 = 24*ETA * (1+2*ETA)*(1+2*ETA);
	e6 = -e6;
	


	double q=PI/1000;
	double haha=chat_ana(q);
	printf("%f\n",haha);

	return (0);
	}


double chat_ana(double q)
{
	int i, j,minIndex;
	double q2, q3, sinq, cosq, sum,temp, 
		   t[7];
 
 
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
 
