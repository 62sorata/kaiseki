#include <stdio.h>
#include <math.h>

#define PI 3.141592
#define smallAmountX 10e-8
#define FunctionA(x) sin(PI*x)
#define FunctionB(x) cos(PI*x)

#define FunctionX 0.1
#define a 0
#define N 20 //N次傾
#define X 1.0f //xの値

int main (void){
	
	double differentialX;

	double Factorial =1;
	printf("%4f", FunctionA(FunctionX));

	for (int x=1; x<=N; x++){
		//階乗計算
		Factorial = Factorial * x;

		if (x%4 == 1) {
			differentialX = pow(PI,x) * FunctionB(FunctionX);
		}else if (x%4 == 2) {
			differentialX = -1*pow(PI,x) * FunctionA(FunctionX);
		}else if (x%4 == 3) {
			differentialX = -1*pow(PI,x) * FunctionB(FunctionX);
		}else if (x%4 == 0) {
			differentialX = pow(PI,x) * FunctionA(FunctionX);
		}

		printf("+%4f(x-%f)^%d", differentialX/Factorial, FunctionX, x);
	}
	printf("\n");
	
	return 0;

}
