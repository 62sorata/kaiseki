#include <stdio.h>
#include <math.h>
#include <complex.h>

const float L=1;  //周期
const int N=20; //標本数
const float PI = 3.1415926535;

#define fx(x) exp(sin(2*PI*x))

int main(void) {

	float DELx = L/N;
	float List[N][2];
	for (int i=0; i<N; i++) {
		List[i][0] = i*DELx;
		List[i][1] = fx(i*DELx);
	}

	double fList[2*N+1];

	for(int n=-N; n<=N; n++) {
		double complex Fn = 0;

		for(int m=0; m<=N-1; m++) {
			Fn = Fn + List[m][1]*cexp(-(2*PI*m*n*I)/N);
		}
		//printf("%4f\n",Fn);
		//Fn = sqrt(pow(creal(Fn),2)+pow(cimag(Fn),2));
		//Fn = abs(Fn);
		//printf("%4f\n",Fn);
		fList[n] = cabs(Fn/N);
		printf("%4f\n",fList[n]);
	}

}
