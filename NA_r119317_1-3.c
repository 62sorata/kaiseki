#include<stdio.h>
#define n 10
float xi[n]={0.9976 ,1.4959 ,0.2213 ,1.3690 ,4.5026 ,3.9716 ,4.5249 ,3.2103 ,5.3856 ,3.3002};
float yi[n]={5.8289, 5.8261, 3.8695, 5.1005, 9.9896, 7.9864 ,10.1420 ,8.1430 ,12.7669 ,7.6869};

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

	printf("yi=%4fxi + %4f", A, B);


	return 0;
}
