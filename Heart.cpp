#include <stdio.h>
#include "baseCUI.cpp"
#include <math.h>

void heart() {
	float h, x, y;
	float maxX = -999.0, maxY = -999.0;
	float minX = 999.0, minY = 999.0;
	
	for(int i = 0; i < 100; i++) {
		h = 3.141592 * i / 50.0;
		x = 140 * pow(sin(h), 3);
		y = 110*cos(h)-45*cos(2*h)-15*cos(3*h)-10*cos(4*h);
		
		printf("[%2d] x:%7.2f y:%7.2f\n", i, x, y);
	}
}

int main() {
	init(100, 50, 0);
	heart();
	getch();
	return 0;	
}
