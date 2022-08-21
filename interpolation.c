#include<stdio.h>
#include<math.h>

void Math_magic(float xy[3][2]){

	float a1=0,a2=0,a0=0;
	float a2_de=0,a2_mo=0,a1_de =0,a1_mo=0;

	a2_de=((pow(xy[1][0],2))-(pow(xy[0][0],2)))*(xy[0][0]-xy[2][0]) + ((pow(xy[0][0],2))-(pow(xy[2][0],2)))*(xy[0][0]-xy[1][0]);

	a2_mo=(xy[0][1]-xy[2][1])*(xy[0][0]-xy[1][0])-(xy[0][1]-xy[1][1])*(xy[0][0]-xy[2][0]);

	a2 = a2_mo/a2_de;

	a1_de = xy[0][1]-xy[1][1]+a2*(pow(xy[1][0],2)-pow(xy[0][0],2));
	a1_mo = xy[0][0]-xy[1][0];

	a1 = a1_mo/a1_de;

	a0 = xy[0][1]-a1*xy[0][0]-a2*pow(xy[0][0],2);

	printf("%4fx^2 + %4fx + %4f\n",a2,a1,a0);

	float Pn = a2*0.5*0.5 + a1 *0.5 +a0;

	printf("Pn= %5f\n",Pn);

	float Ans = exp(0.5)-Pn;

	printf("Fx-Pn=%5f",Ans);







	//printf("%4f\n",xy[2][0]);
	

}

int main(void){


	//float la[3][2] = {};
	//float lb[3][2] = {};



	float la[3][2] = {{0,0},{1,1},{2,0}};
	float lb[3][2] = {{0,0},{1,1},{2,2}};

	Math_magic(la);

	Math_magic(lb);

	float x0=-1,x1=0,x2=1,y0=0,y1=0,y2=0;

	y0=exp(x0);
	y1=exp(x1);
	y2=exp(x2);

	float lc[3][2]= {{x0,y0},{x1,y1},{x2,y2}};

	Math_magic(lc);

	//float a1=0,a2=0,a0=0;

	//float a2_de=0,a2_mo=0,a1_de =0,a1_mo=0;

	//a2_de=((pow(la[1][0],2))-(pow(la[0][0],2)))*(la[0][0]-la[2][0]) + ((pow(la[0][0],2))-(pow(la[2][0],2)))*(la[0][0]-la[1][0]);
	
	//a2_mo=(la[0][1]-la[2][1])*(la[0][0]-la[1][0])-(la[0][1]-la[1][1])*(la[0][0]-la[2][0]);
	//a2 = a2_mo/a2_de;


	//a1_de = la[0][1]-la[1][1]+a2*(pow(la[1][0],2)-pow(la[0][0],2));
	///a1_mo = la[0][0]-la[1][0];
    
	//a1 = a1_mo/a1_de;

	//a0 = la[0][1]-a1*la[0][0]-a2*pow(la[0][0],2);



	//printf("a2 = %4f\n", a2);
	//printf("%4fx^2 + %4fx + %4f",a2,a1,a0);
	


	return 0;
}
