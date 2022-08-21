#include<stdio.h>
#include<math.h>

#define n 7

float xi[n] = {0.0 ,0.5 ,1.0 ,1.5 ,2.0 ,2.5 ,3.0};
float yi[n] = {1.00 ,1.54 ,2.20 ,1.76 ,0.84 ,-0.66 ,-1.82};
int main(void){

	float Sx=0, Sy=0, Sxx =0, Sxxx=0, Sxxxx=0, Sxy=0, Sxxy=0;  //ｘとｙの総和

	for(int x=0; x<n; x++){
		Sx =Sx + xi[x]; //ｘの総和
		Sy = Sy + yi[x];//ｙの総和

		printf("yi = %4f \n", yi[x]);

		Sxx = Sxx + pow(xi[x], 2);  // x^2の総和
		Sxxx = Sxx + pow(xi[x], 3);  // x^3の総和
		Sxxxx = Sxxxx + pow(xi[x], 4);  // x^4の総和

		Sxy = Sxy + xi[x] * yi[x];  //x*yの総和
		Sxxy = Sxxy + pow(xi[x], 2) * yi[x];  // x*x*yの総和
	}
	printf("Sx = %4f , Sy = %4f \n",Sx ,Sy);

	printf("Sxy = %4f",Sxy);


	float A=0, A_de =0, A_mo=0;

	A_de = n * pow(Sxx, 3) -pow(n,2)*Sxxxx*Sxx +pow(Sxx,2)*pow(Sx,2) -n*Sxxxx*pow(Sx,2) +n*Sxxx*Sxx*Sx +pow(n,2)*Sxxxx*Sxxx -n*Sxxxx*Sxx*Sx -pow(Sxx,2)*pow(Sx,2);
	A_mo = pow(n,2)*pow(Sxx,2)*Sy +n*pow(Sxx,2)*Sy +n*Sxx*pow(Sx,2)*Sy +Sxx*pow(Sx,2)*Sy +pow(n,2)*Sxxxx*Sxy -n*Sxxxx*Sx*Sy +n*Sxx*Sx*Sxy -Sxx*pow(Sx,2)*Sy;

	printf("分母＝ %4f, 分子＝ %4f \n",A_de,A_mo);
	A = A_mo / A_de;

	printf("A = %4f \n",A );

	float B=0,B_de=0,B_mo=0;

	B_de=n*Sxxxx +Sxx*Sx;
	B_mo=A*pow(Sxx,2) -n*A*Sxxxx -n*Sxx*Sy -Sxx*Sy;
	B =B_mo/B_de

	printf("B = %4f \n",B);

	float c=0, c_de=0 ,c_mo=0;

	c_de=n;
	c_mo=Sy -A*Sxx +B*Sx;
	c = c_mo/c_de;

	printf("C = %4f \n",)



	return 0;

}