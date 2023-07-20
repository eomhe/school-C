#include <stdio.h>
#include "baseCUI.cpp"
#include <math.h>

void heart(){
	float h,x,y;
	float maxX = -999.0, maxY = -999.0;
	float minX = 999.0, minY = 999.0;
	
	for(int i = 0; i<100; i++){
		h = 3.141592*i/50.0;
		x = ((140*pow(sin(h),3)) + 140) / 3;
		y = ((110*cos(h)-45*cos(2*h)-15*cos(3*h)-10*cos(3*h)) + 150) / 6;
		
		//printf("[%2d] x:%7.2f, y:%7.f\n", i, x, y);
		
		if(minX>x) minX = x;
		if(maxX<x) maxX = x;
		if(minY>y) minY = y;
		if(maxY<y) maxY = y;
		y = 45 - y;
		x = x + 2;
		setColor(15,i); gotoXY(x,y); puts("love");
	}
	//printf("x:%7.2f~%7.2f, y:%7.2f~%7.2f\n", minX,maxX,minY,maxY);
	//x:-140~140    + 140 0~280
	//y:-150~100.99 + 150 0~250.99
}

int main(){
	init(100, 50, 0);
	heart();
	getch();
	
	return 0;
}
