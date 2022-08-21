#include <stdio.h>
#include <math.h>


#define A 0.0 //区分[a,b]
#define B 1.0
#define PI 3.141592
#define nmax 10 //ｎの範囲の最大
#define N(x) pow(2.0,x) 
#define fx(x) exp(2*sin(PI*x))


double f (double x) {
	return fx(x);
}


int main(void){
	double h=0,T=0;
	double Flist[2][nmax][nmax]={{}}; //一覧を保存するリスト 0:近似値 1:誤差

	
	//台形
	for (int n=0; n <= nmax; n++){
		T=0;
		h = (B-A)/N(n);
		for (double i=0; i<=N(n)-1; i++) {
			T = T + (h/2)*( f(A+i*h) + f(A+ i*h +h) );
		}
		Flist[0][0][n] = T;
	}

	for (int i=1; i<=nmax; i++) {
		printf("N=2^%d:%.10f\n",i,Flist[0][0][i]);
	}
	

	return 0;


}
