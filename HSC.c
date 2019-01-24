// Solve the PRISM-PY equations for the HSC model.
#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <mpfr.h>

int de;
// # define PI 3.141592653589793
// # define QPI 12.56637061435917 //Pi*4
// # define ETA 0.445058959258554   //0.85*pi/6.0
// # define DPI2 0.050660591821169 // 1/2/pi/pi

double e0, e1, e2, e3, e4, e5, e6;
void
chat_ana (mpfr_t q, mpfr_t e0, mpfr_t e1, mpfr_t e2, mpfr_t e3, mpfr_t e4,
	  mpfr_t e5, mpfr_t e6, mpfr_t PI, mpfr_t ETA, mpfr_t result);
int
main ()
{
  mpfr_set_default_prec (102400);
  mpfr_t sum, e0, e1, e2, e3, e4, e5, e6, PI, ETA, QPI, DPI2, C, OneMETA,
      twoPETA, temp, q, result;
  mpfr_init (sum);
  mpfr_init (e0);
  mpfr_init (e1);
  mpfr_init (e2);
  mpfr_init (e3);
  mpfr_init (e4);
  mpfr_init (e5);
  mpfr_init (e6);
  mpfr_init (PI);
  mpfr_init (ETA);
  mpfr_init (QPI);
  mpfr_init (DPI2);
  mpfr_init (C); // 0.85/6
  mpfr_init (OneMETA); // 1-ETA
  mpfr_init (twoPETA); // 2+ETA
  mpfr_init (temp);
  mpfr_init (q);
  mpfr_init (result);

  mpfr_set_str (
      PI,
      "3.14159265358979323846264338327950288419716939937510582097494459230781640628"
      "62089986280348253421170679821480865132823066470938446095505822317253594081284811"
      "174502841027019385211055596446229489549303819644288109756659334461284756482337867831652"
      "7120190914564856692346034861",
      10, MPFR_RNDN);
  mpfr_set_str (C,
		"0.1416666666666666666666666666666666666666666666666666666666"
		"66666666666666666666666666666666666666666666666666"
		"6666666666666666666666666666666666666666666666666666666666",
		10, MPFR_RNDN);
  //e0

  mpfr_mul_ui (QPI, PI, 4, MPFR_RNDN);
  mpfr_mul (ETA, PI, C, MPFR_RNDN);
  mpfr_ui_sub (OneMETA, 1, ETA, MPFR_RNDN);
  mpfr_add_ui (twoPETA, ETA, 2, MPFR_RNDN);
  mpfr_mul (temp, OneMETA, OneMETA, MPFR_RNDN);
  mpfr_mul (e0, temp, twoPETA, MPFR_RNDN);
  //e1 = -2 * (1-ETA*(6-5*ETA*ETA));
  mpfr_mul (temp, ETA, ETA, MPFR_RNDN);
  mpfr_mul_ui (temp, temp, 5, MPFR_RNDN);
  mpfr_ui_sub (temp, 6, temp, MPFR_RNDN);
  mpfr_mul (temp, ETA, temp, MPFR_RNDN);
  mpfr_ui_sub (temp, 1, temp, MPFR_RNDN);
  mpfr_mul_si (e1, temp, -2., MPFR_RNDN);
  //e2= 6*ETA * (2-ETA*(4+7*ETA));
  mpfr_mul_ui (temp, ETA, 7, MPFR_RNDN);
  mpfr_add_ui (temp, temp, 4, MPFR_RNDN);
  mpfr_mul (temp, ETA, temp, MPFR_RNDN);
  mpfr_ui_sub (temp, 2, temp, MPFR_RNDN);
  mpfr_mul_ui (temp, temp, 6, MPFR_RNDN);
  mpfr_mul (e2, temp, ETA, MPFR_RNDN);
  //e3=-6*ETA * (2+ETA)*(2+ETA);
  mpfr_mul (temp, twoPETA, twoPETA, MPFR_RNDN);
  mpfr_mul (temp, ETA, temp, MPFR_RNDN);
  mpfr_mul_si (e3, temp, -6, MPFR_RNDN);
  //e4=24*ETA * (1+2*ETA)*(1+2*ETA);
  mpfr_mul_ui (temp, ETA, 2, MPFR_RNDN);
  mpfr_add_ui (temp, temp, 1, MPFR_RNDN);
  mpfr_mul (temp, temp, temp, MPFR_RNDN);
  mpfr_mul (temp, temp, ETA, MPFR_RNDN);
  mpfr_mul_ui (e4, temp, 24, MPFR_RNDN);
  //e5
  mpfr_set (e5, e4, MPFR_RNDN);
  //e6
  mpfr_mul_si (e6, e5, -1, MPFR_RNDN);
  // e0 = (1-ETA)*(1-ETA) * (2+ETA);
  // e1 = -2 * (1-ETA*(6-5*ETA*ETA));
  // e2 = 6*ETA * (2-ETA*(4+7*ETA));
  // e3 = -6*ETA * (2+ETA)*(2+ETA);
  // e4 = e5 = e6 = 24*ETA * (1+2*ETA)*(1+2*ETA);
  // e6 = -e6;

//  mpfr_printf ("%10.20RF\n", e0);
//  mpfr_printf ("%10.20RF\n", e1);
//  mpfr_printf ("%10.20RF\n", e2);
//  mpfr_printf ("%10.20RF\n", e3);
//  mpfr_printf ("%10.20RF\n", e4);
//  mpfr_printf ("%10.20RF\n", e5);
//  mpfr_printf ("%10.20RF\n", e6);
//  scanf ("%d", &de);
  //q
  mpfr_div_ui (q, PI, 1000, MPFR_RNDN);


//  mpfr_printf ("%10.200RF\n", PI);
  chat_ana (q, e0, e1, e2, e3, e4, e5, e6, PI, ETA, result);
  mpfr_printf ("%10.200RF\n", result);
  return (0);
}

void
chat_ana (mpfr_t q, mpfr_t e0, mpfr_t e1, mpfr_t e2, mpfr_t e3, mpfr_t e4,
	  mpfr_t e5, mpfr_t e6, mpfr_t PI, mpfr_t ETA, mpfr_t result)
{
  int i, j, minIndex;
  mpfr_set_default_prec (1024);
  mpfr_t q2, q3, sinq, cosq, sum, temp, t0, t1, t2, t3, t4, t5, t6, oneMETA,
      upper;
  mpfr_init (q2);
  mpfr_init (q3);
  mpfr_init (sinq);
  mpfr_init (cosq);
  mpfr_init (sum);
  mpfr_init (temp);
  mpfr_init (t0);
  mpfr_init (t1);
  mpfr_init (t2);
  mpfr_init (t3);
  mpfr_init (t4);
  mpfr_init (t5);
  mpfr_init (t6);
  mpfr_init (oneMETA);
  mpfr_init (upper);

  mpfr_mul (q2, q, q, MPFR_RNDN);
  mpfr_mul (q3, q2, q, MPFR_RNDN);
  mpfr_sin (sinq, q, MPFR_RNDN);
  mpfr_cos (cosq, q, MPFR_RNDN);
  //t0
  mpfr_mul (temp, e0, q2, MPFR_RNDN);
  mpfr_mul (temp, temp, q2, MPFR_RNDN);
  mpfr_mul (t0, temp, cosq, MPFR_RNDN);
  //t1
  mpfr_mul (temp, e1, q3, MPFR_RNDN);
  mpfr_mul (t1, temp, sinq, MPFR_RNDN);
  //t2
  mpfr_mul (temp, e2, q2, MPFR_RNDN);
  mpfr_mul (t2, temp, cosq, MPFR_RNDN);
  //t3
  mpfr_mul (t3, e3, q2, MPFR_RNDN);
  //t4
  mpfr_mul (temp, e4, q, MPFR_RNDN);
  mpfr_mul (t4, temp, sinq, MPFR_RNDN);
  //t5
  mpfr_mul (t5, e5, cosq, MPFR_RNDN);
  mpfr_set (t6, e6, MPFR_RNDN);
  // q2=q*q;  q3=q*q2;  sinq=sin(q);  cosq=cos(q);
  // t[0] = e0 * q2 *q2* cosq;
  // t[1] = e1 * q3 * sinq;
  // t[2] = e2 * q2 * cosq;
  // t[3] = e3 * q2;
  // t[4] = e4 * q * sinq;
  // t[5] = e5 * cosq;
  // t[6] = e6;




  mpfr_set_si (sum, 0, MPFR_RNDN);
  mpfr_add (sum, sum, t0, MPFR_RNDN);
  mpfr_add (sum, sum, t1, MPFR_RNDN);
  mpfr_add (sum, sum, t2, MPFR_RNDN);
  mpfr_add (sum, sum, t3, MPFR_RNDN);
  mpfr_add (sum, sum, t4, MPFR_RNDN);
  mpfr_add (sum, sum, t5, MPFR_RNDN);
  mpfr_add (sum, sum, t6, MPFR_RNDN);

  printf("debug\n");
  mpfr_printf ("%10.200RF\n", q);
  mpfr_printf ("%10.200RF\n", t0);
  mpfr_printf ("%10.200RF\n", t1);
  mpfr_printf ("%10.200RF\n", t2);
  mpfr_printf ("%10.200RF\n", t3);
  mpfr_printf ("%10.200RF\n", t4);
  mpfr_printf ("%10.200RF\n", t5);
  mpfr_printf ("%10.200RF\n", t6);
  mpfr_printf ("%10.200RF\n", sum);
//  scanf ("%d", &de);

  // return (2*PI*sum / pow((1-ETA)*(1-ETA)*q3,2));
  mpfr_ui_sub (oneMETA, 1, ETA, MPFR_RNDN);
  mpfr_mul (temp, oneMETA, oneMETA, MPFR_RNDN);
  mpfr_mul (temp, temp, q3, MPFR_RNDN);
  mpfr_mul (temp, temp, temp, MPFR_RNDN);
  mpfr_mul (upper, PI, sum, MPFR_RNDN);
  mpfr_mul_ui (upper, upper, 2, MPFR_RNDN);
  mpfr_div (result, upper, temp, MPFR_RNDN);



  mpfr_clear (q2);
  mpfr_clear (q3);
  mpfr_clear (sinq);
  mpfr_clear (cosq);
  mpfr_clear (sum);
  mpfr_clear (temp);
  mpfr_clear (t0);
  mpfr_clear (t1);
  mpfr_clear (t2);
  mpfr_clear (t3);
  mpfr_clear (t4);
  mpfr_clear (t5);
  mpfr_clear (t6);
  mpfr_clear (oneMETA);
  mpfr_clear (upper);

}

