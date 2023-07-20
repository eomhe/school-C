#include <stdio.h>
#include "baseCUI.cpp"

#define SX 0
#define EX 78
#define SY 1
#define EY 22

int ch;
char playerStr[] = {"бс"};
int playerX = 40, playerY = 12;

char ballStr[] = {"б▄"};
int ballX = 20, ballY = 12;

void infoDisp() {
	setColor(15,0); gotoXY(0, 23);
	printf(" player[%2d,%2d] ball[%2d,%2d]", playerX, playerY, ballX, ballY);
}

int main(){
	init(80, 25, 0);
	
	for(int i = 0; i <= 79; i++){
		setColor(8, 0); gotoXY(i, 0); puts(" ");
		setColor(8, 0); gotoXY(i, 22); puts(" ");
	}
	setColor(15, 0); gotoXY(playerX, playerY); puts(playerStr);
	setColor(15, 12); gotoXY(ballX, ballY); puts(ballStr);
	
	while(1){
		
		infoDisp();
	}
	
	return 0;
}
