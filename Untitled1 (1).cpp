#include <stdio.h>
#include "baseCUI.cpp"
int main() {
	init(80, 25, 1);
	for(int x = 0; x < 80; x++){
		if(x % 3 == 0)
			continue;
		setColor(15, 4); gotoXY(x, 10); printf("A");
		Sleep(100);
		setColor(15, 4); gotoXY(x, 10); printf(" ");
	}

	return 0;
}
