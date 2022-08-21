#include <stdio.h>
#include <math.h>

#define Fx 1/(1+25*x*x)
#define N 11 //要素数

double f(double x) {
	return Fx;
}

int main(void) {

	float list_x[11] = {-2.5 ,-2.0 ,-1.5 ,-1.0 ,-0.5 ,0.0 ,0.5 ,1.0 ,1.5 ,2.0 ,2.5}, 
		  list_y[11] ={};

	for (int i=0; i<11; i++) {
		list_y[i] = f(list_x[i]);
	}

	//y=a0+a1x0+a2x^2...

	//二次元配列に
	float list_main[11][11] = {{}};
	for(int i=0; i<11; i++) {
		for (int j=0; j<11; j++){
			list_main[i][j] = pow(list_x[i],j);
		}
		//list_main[i][0] = list_x[i];
		//list_main[i][1] = list_y[i];
	}

	float inv_list[11][11];//逆行列
	float buf; //一時的なデータを蓄える


	//単位行列を作る
	for (int i=0; i<N; i++) {
		for (int j=0; j<N ; j++) {
			inv_list[i][j] = (i==j) ?1.0:0.0;
		}
	}

	//掃き出し法
	for (int i=0; i<N; i++) {
		buf = 1/list_main[i][i];

		for (int j=0; j<N; j++) {
			list_main[i][j]*=buf;
			inv_list[i][j]*=buf;
		}
		for (int j=0; j<N; j++) {
			if (i!=j) {
				buf = list_main[j][i];
				for (int k=0; k<N; k++) {
					list_main[j][k] -= list_main[i][k] * buf;
					inv_list[j][k] -= inv_list[i][k] * buf;
				}
			}
		}
	}

	//逆行列を出力
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			printf(" %4f", inv_list[i][j]);
		}
		printf("\n");
	}

	float a[N] ={};

	//係数の配列を出力
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			a[i] = a[i] + inv_list[i][j]*list_y[i];
		}
	}

	//出力
	printf("y=%4f",a[0]);
	for (int i=1; i<N; i++) {
		printf("+%4f*x^%d",a[i], i);
	}
	printf("\n");

}