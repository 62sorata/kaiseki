#include <stdio.h>
#include <math.h>

#define smallAmountX 10e-8
#define Function (atan(x))-(1/2)
#define EPSILON pow(10,-4)


#define FunctionX 0

//関数呼び出し関数
float f(float x) {
	return Function;
}
//微分公式
float fd(float x){
	return (f(x + smallAmountX) - f(x)) / smallAmountX;
}

int main(void){

	float xn =1.0, fxn=0 ,fxnb =0, a =0;
	double b=0;

	while(1) {
		fxn =f(xn);
		fxnb = fd(xn);

		printf("%4f\n",fxnb);

		a = xn - fxn/fxnb;

		printf("%4f\n",a);

		b=fabsf((a-xn)/a);

		if ( b> EPSILON) {
			break;
		}
		printf("%4f",b);
		//xnの更新
		xn =a;

	}

	printf("xn=%4f\n f(xn)=%4f\n", a,f(a));

	return 0;
	
}