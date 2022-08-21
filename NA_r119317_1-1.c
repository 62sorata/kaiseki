#include <stdio.h>
#include <math.h>

#define EPSILON pow(10,-4)

float fx(float x) {
	float y;

	y = atan(x)-(1/2);

	return y;
}


int main(void) {
	float a=-3.375 ,b=3.375 ,c=0, f=0,absc=0;

	//規定の誤差以下になるまで反復計算
	while(1) {
		c =(a + b) / 2;

		absc=fabsf(a-b)/2;
		f = fx(c);

		if (absc < EPSILON){
			break;
		}

		if(c <0) {
			a =c;
		}else{
			b=c;
		}
	}
	printf("c=%4f,f(c)=%4f\n", c,f);
	return 0;
}