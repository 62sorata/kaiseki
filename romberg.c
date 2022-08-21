#include <stdio.h>
#include <math.h>


#define A 0.0 //区分[a,b]
#define B 1.0
#define nmax 4 //ｎの範囲の最大
#define N(x) pow(2.0,x) 
#define fx(x) 5*exp(-x)*log(1+x)
//#define fx(x) exp(x)
//#define TN 1.718281828 //(0~1) exp(x)dx　の真値
#define TN 1.042136976145755321

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

	int count =1;
	for (int k=1; k<=nmax; k++) {
		for (int n=count; n<=nmax; n++) {

			T = (pow(4,k)*Flist[0][k-1][n] - Flist[0][k-1][n-1])/(pow(4,k)-1);
			Flist[0][k][n] = T;
			Flist[1][k][n] = TN - T;
		}
		count++;
	}

	//printf("T4(4)積分結果=%10f\ne4(4)誤差=%10f\n",Flist[0][0][0],Flist[1][1][1]);

	for(int k=1; k <= nmax; k++) {
		int n=k;	
		printf("e%d(%d)=%.12f\n",n,k,Flist[1][k][n]);
	
	}

	return 0;


}