#include <stdio.h>
#include <math.h>

const int N = 4;
const float PI = 3.1415926535;

int main(void) {

	float an = 0, bn = 0;

	printf("f(x) = π/4");

	for (int n=1; n<=N; n++) {

		an = -(1+pow(-1,n+1))/(pow(n,2)*PI);
		bn = pow(-1,n-1)/n;

		printf("+ %4fcos%dx + %4fsin%dx",an,n,bn,n);

	}

}