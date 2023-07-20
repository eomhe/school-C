#include <stdio.h>
#include "baseCUI.cpp"
#include <stdio.h>
#include <math.h>

int ch;
int ballX = 40, ballY = 0;
float g = 0.098;
float v = 0;
float s = 0;
float t = -0.9;

void wallDisp(){
	int i;
	for(i = 0; i<=45; i++){
		gotoXY(38, i); printf("¦¢");
		gotoXY(42, i); printf("¦¢");
	}
	gotoXY(38, 46); printf("¦¦");
	gotoXY(40, 46); printf("¦¡"); 
	gotoXY(42, 46); printf("¦¥");
}
void infoDisp(){
	gotoXY(0, 48); printf("ball[%2d,%2d]", ballX, ballY);
}

int main() {
	init(80, 50, 1);
	wallDisp();
	infoDisp();
	setColor(15, 12); gotoXY(ballX, 0); printf("¡Ü");
	ch = keyInput();
	while(1){
		infoDisp();
		setColor(15, 12); gotoXY(ballX, ballY); printf(" ");
		v = v+g;
		s = s+v;
		ballY = s;
		setColor(15, 12); gotoXY(ballX, ballY); printf("¡Ü");
		
		if(ballY >= 45){
			v = t*fabs(v)-g;
		}
		infoDisp();
		Sleep(1000 / 30);
	}
	return 0;
}
