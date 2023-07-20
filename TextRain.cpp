#include <stdio.h>
#include <time.h>
#include "baseCUI.cpp"

#define FPS 30
#define W 200
#define H 50
#define TextCount 100

int frameCount;
clock_t currentTime, oldTime;

char p[] = "ABas03580(ALKFDJLKDGJLIO)(*%&*&$#^&*0=+_@#$)*&(^@%$#$()%*))ljkflk2490sdfjkllksjdfjklasfjlkjkafslkjaslfjlaksjflkasdjlffsjadlk";
int pX[TextCount] = {0};
int pY[TextCount] = {0};
int pFps[TextCount] = {0};
int pColor[TextCount];

int main() {
	srand((int)time(NULL));
	init(W, H, 0);
	
	for(int i = 0; i < TextCount; i++) {
		pX[i] = rand() % W;
		pY[i] = 0;
		pFps[i] =( (rand() % 10) + 1 ) * 3;
		pColor[i] = rand() % 16;
	}

	oldTime = clock();	
	while(1) {
		for(int i = 0; i < TextCount; i++) {
			if(frameCount % pFps[i] == 0) {
				setColor(15, pColor[i]); gotoXY(pX[i], pY[i]); putchar(' ');
				pY[i]++;
				if(pY[i] > H - 1) {
					pX[i] = rand() % W;
					pY[i] = 0;
					pFps[i] =( (rand() % 10) + 1 ) * 3;
					pColor[i] = rand() % 16;
				}
				setColor(15, pColor[i]); gotoXY(pX[i], pY[i]); putchar(p[i]);			
			}			
		}


		while(1) {
			currentTime = clock();
			if(currentTime - oldTime > (1000 / FPS)) {
				oldTime = currentTime;
				frameCount++;
				break;
			}
		}
	}
	
	return 0;
}
