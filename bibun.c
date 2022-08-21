#include <stdio.h>
#include <math.h>

#define smallAmountX 10e-8
//#define Function sqrt(1+x)
//#define Function cos(x)
#define Function exp(1+x)

#define FunctionX 0
#define a 0
#define N 4 //N次傾
#define X 1 //xの値

double f(double x) {
	return Function;
}

double fd(double x){
	return (f(x + smallAmountX) - f(x)) / smallAmountX;
}

int main (void){
	
	double differentialX;

	double Factorial =1;

	float approximate=f(FunctionX);//近似値保持用

	//printf("%4f\n",approximate);

	printf("%4f",f(FunctionX) );

	for (int x=1; x<=N; x++){
		//階乗計算
		Factorial = Factorial * x;

		differentialX = fd(FunctionX);

		approximate = approximate + (differentialX/Factorial)*(pow(X-FunctionX,x));
		//printf("%4f\n",approximate);

		printf("+%4f(x-%d)^%d", differentialX/Factorial, FunctionX, x);
	}
	printf("\n");

	printf("近似値=%4f\n",approximate);
	printf("誤差(真値ー近似値)=%4f",f(X)-approximate);

	
	
	


	return 0;

}
