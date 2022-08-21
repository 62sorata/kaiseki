#include<stdio.h>
#define n 7
float xi[n]={1.0 ,2.0 ,3.0 ,4.0 ,5.0 ,6.0 ,7.0};
float yi[n]={0.9, 1.7, 2.1, 2.6, 3.0, 3.9, 4.5};

int main(void){
	float Sx=0 , Sy=0 ,Sxx=0 ,Sxy=0;
	
	//総和
	for(int x=0; x<n; x++){
		Sx= Sx +xi[x];
		Sy= Sy + yi[x];
		Sxx = Sxx + xi[x]*xi[x];
		Sxy = Sxy + xi[x] * yi[x];
	}
	
	printf("Sx= %4f, Sy= %4f, Sxx= %4f, Sxy= %4f\n",Sx,Sy,Sxx,Sxy);

	float A=0, A_de=0, A_mo; //Aの初期値、Aの分母、Aの分子

	A_de= Sx *Sx - n * Sxx;
	A_mo=Sy * Sx - n * Sxy;

	A = A_mo/A_de;

	printf("A= %4f\n",A);

	float B=0,B_de=0, B_mo=0; //Bの初期値、Bの分母、Bの分子

	B_de = n;
	B_mo = Sy - A * Sx;

	B = B_mo/B_de;

	printf("B= %4f\n",B);



	return 0;
}
