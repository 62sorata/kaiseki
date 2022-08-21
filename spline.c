#include<stdio.h>

#define N 3  // 配列の次数

float list[5][2]={{0,0},{1,1},{2,0},{3,-1},{4,0}};

int main(void){
	
	float h0=0,h1=0,h2=0,h3=0;

	h0=list[1][0]-list[0][0];
	h1=list[2][0]-list[1][0];
	h2=list[3][0]-list[2][0];
	h3=list[4][0]-list[3][0];

	float inv_a[3][3] = {{2*(h0+h1),h1,0},
						{h1,2*(h1+h2),h2},
						{0,h2,2*(h2+h3)}};

	printf("「 %3f %3f 	  0｜「u1｜　「v1|\n", 2*(h0+h1),h1);
	printf("| %3f %3f %3f｜|u2｜=｜v2｜\n", h1, 2*(h1+h2),h2);
	printf("| 0   %3f %3f」｜u3」  |v3」\n", h2,2*(h2+h3));

	//逆行列作成
	float inv_b[3][3];//逆行列を入れる配列

	float buf;// 一時的なデータを蓄える場所
	int i,j,k; //カウンタ

	//単位行列

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			inv_b[i][j] = (j==i)?1.0:00; //（条件式)?式１:式２
		}
	}

	//掃き出し法
	for(i=0;i<N;i++){
		buf=1/inv_a[i][i];

		for( j=0; j<N; j++){
			inv_a[i][j] *=buf;
			inv_b[i][j] *=buf;
		}
		for(j=0;j<N;j++){
			if( i!=j ){
				buf=inv_a[j][i];
				for(k=0;k<N;k++){
					inv_a[j][k] -= inv_a[i][k] * buf;
					inv_b[j][k] -= inv_b[i][k] * buf;
				}
			}
		}

	}
	//逆行列を出力
	for( i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf(" %3f ",inv_b[i][j]);
		}
		printf("\n");
	}

	//uの計算
	float u1=0,u2=0,u3=0,Vn[3]={-12,0,12};

	u1=inv_b[0][0]*Vn[0] + inv_b[0][1]*Vn[1] + inv_b[0][2]*Vn[2];
	u2=inv_b[1][0]*Vn[0] + inv_b[1][1]*Vn[1] + inv_b[1][2]*Vn[2];
	u3=inv_b[2][0]*Vn[0] + inv_b[2][1]*Vn[1] + inv_b[2][2]*Vn[2];

	printf("u1= %3f,u2= %3f,u3= %3f",u1,u2,u3);

	//Snの関数計算

	int c0 =0,c1=0,c2=0,c3=0;

	c0=(list[1][1]-list[0][1])/h0-h0/6;
	c1=(list[2][1]-list[1][1])/h1-h1/6;
	c2=(list[3][1]-list[2][1])/h2-h2/6;
	c3=(list[4][1]-list[3][1])/h3-h3/6;

	int a0=0,a1=0,a2=0,a3=0;

	a0=u1/(6*h0);
	a1=(u2-u1)/(6*h1);
	a2=(u3-u2)/(6*h2);
	a3=(0-u3)/(6*h3);

	int b0=0,b1=0,b2=0,b3=0;

	b1=u1/2;
	b2=u2/2;
	b3=u3/2;

	int d0=0,d1=0,d2=0,d3=0;

	d0=list[0][1];
	d1=list[1][1];
	d2=list[2][1];
	d3=list[3][1];

	printf("S0=%3fX^3+%3fX^2+%3fX+%3f",a0,b0,c0,d0);
	printf("S1=%3fX^3+%3fX^2+%3fX+%3f",a1,b1,c1,d1);
	printf("S2=%3fX^3+%3fX^2+%3fX+%3f",a2,b2,c2,d2);
	printf("S3=%3fX^3+%3fX^2+%3fX+%3f",a3,b3,c3,d3);



}