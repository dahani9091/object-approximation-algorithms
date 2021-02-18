/*#include<graphics.h>
#include<conio.h>
#include<math.h>
int x[4],y[4];
void bezier(int x[4],int y[4]){
	int gr = DETECT, gm, i;
	double t, xt, yt;
	initgraph(&gr, &gm,"C:\\TC\\BGI");
	for(t=0.0;t<1.0;t+=0.0005){
		xt=pow((1.0-t),3)*x[0]+3*t*pow((1.0-t),2)*x[1]+3*pow(t,2)*(1.0-t)*x[2]+pow(t,3)*x[3];
		yt=pow((1.0)-t,3)*y[0]+3*t*pow((1.0)-t,2)*y[1]+3*pow(t,2)*(1.0-t)*y[2]+pow(t,3)*y[3];
		putpixel(xt,yt,4);

	}
	for(i=0;i<4;i++){
		putpixel(x[i],y[i],5);
		circle(x[i],y[i],2);
		delay(2);
	}
	getch();
	closegraph();
}

int main(){
	int i,x[4],y[4];
	printf("Enter the four control points :");
	for(i=0;i<4;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	bezier(x,y);
}

*/
