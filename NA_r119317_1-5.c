#include <stdio.h>

#define Fx 1/(1+25*x*x)
#define N 6 //要素数

double f(double x) {
	return Fx;
}

int main(void) {
	
	float list_x[N] = {-1.6 ,-1.4 ,-1.2 ,1.2 ,1.4 ,1.6 }, 
		  list_y[N] ={};

	for (int i=0; i<N; i++) {
		list_y[i] = f(list_x[i]);
	}

	float h[N-1] = {};
	//hの配列作成
	for (int i=0; i<N-1; i++) {
		h[i] = list_x[i+1] - list_x[i];
		//printf("h=%4f\n",h[i]);
	}



	//スプライン補間の行列作成
	float sp[N-2][N-2] = {{}};

	for (int i=0; i<N-2; i++) {
		if (i==0) { //1行目
			for (int j=0; j<N-2; j++) {
				if (j==0) {
					sp[i][j] = 2*(h[j] + h[j+1]);
				}else if (j==1){
					sp[i][j] = h[j+1];
				}else {
					sp[i][j] = 0;
				}
			}
		}else if (i == N-3) { //N-2行目
			for (int j=0; j<N-2; j++) {
				if (j == N-3) {
					sp[i][j] = 2*(h[N-3]+h[N-2]);
				}else if (j == N-4){
					sp[i][j] = h[N-3];
				}else {
					sp[i][j] = 0;
				}
			}
		}else {
			for (int j=0; j<N-2; j++) {
				if (j==i) {
					sp[i][j] = 2*(h[j]+h[j+1]);
				}else if (j == i-1){
					sp[i][j] = h[j];
				}else if (j == i+1){
					sp[i][j] = h[j+1];
				}else {
					sp[i][j] = 0;
				}
			}
		}
	}

	for (int i=0; i<N-2; i++){
		for (int j=0; j<N-2; j++) {
			printf("%4f ",sp[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	float inv_list[N-2][N-2] = {{}};//逆行列
	float buf; //一時的なデータを蓄える

	//単位行列を作る
	for (int i=0; i<N-2; i++) {
		for (int j=0; j<N-2 ; j++) {
			inv_list[i][j] = (i==j) ?1.0:0.0;
		}
	}

	//掃き出し法
	for (int i=0; i<N-2; i++) {
		buf = 1/sp[i][i];

		for (int j=0; j<N-2; j++) {
			sp[i][j]*=buf;
			inv_list[i][j]*=buf;
		}
		for (int j=0; j<N-2; j++) {
			if (i!=j) {
				buf = sp[j][i];
				for (int k=0; k<N-2; k++) {
					sp[j][k] -= sp[i][k] * buf;
					inv_list[j][k] -= inv_list[i][k] * buf;
				}
			}
		}
	}

	//逆行列を出力
	for (int i=0; i<N-2; i++) {
		for (int j=0; j<N-2; j++) {
			printf(" %4f", inv_list[i][j]);
		}
		printf("\n");
	}

	float u[N-2] ={};

	//係数の配列を出力
	for (int i=0; i<N-2; i++) {
		for (int j=0; j<N-2; j++) {
			u[i] = u[i] + (inv_list[i][j]*list_y[j]);

			printf("u=%4f\n",u[i]);
		}
		printf("\n");
	}

	float aj=0, bj=0, cj=0, dj=0;

	for (int i=0; i<N-2; i++) {
		aj = (u[i+1] - u[i])/(6*h[i]);
		bj = u[i]/2;
		cj = (list_y[i+1]-list_y[i])/h[i] - h[i]*(u[i+1]+2*u[i])/6;
		dj = list_y[i];

		printf("S_%d = %4f(x-(%2f)^3 + %4f(x-(%2f)^2 + %4f(x-(%2f)^1 + %4f\n",i, aj, list_x[i], bj, list_x[i], cj, list_x[i], dj);
	}
	return 0;
}