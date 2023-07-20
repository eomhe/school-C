#include <stdio.h>
#include "baseCUI.cpp"

void dispTitle();
void dispBoard();

char ch;
int titleX = 5, titleY = 1;
int boardX = 20, boardY = 8;
int playerX, playerY;
int status = 1;

char title[5][60] = {
	{"##### ##### #####  #####   #   #####  #####  ###  #####"},
	{"  #     #   #        #    # #  #        #   #   # #    "},
	{"  #     #   #        #   ##### #        #   #   # ###  "},
	{"  #     #   #        #   #   # #        #   #   # #    "},
	{"  #   ##### #####    #   #   # #####    #    ###  #####"},
};

//¤² : ¼±  ¤±:¡Û  ¤§:¡¿ 
char board[7][15] = {
    //0123456789012345678901234567890123456789012345678901234567890123456789
	{"¦£¦¡¦¨¦¡¦¨¦¡¦¤"},
	{"¦¢  ¦¢  ¦¢  ¦¢"},
	{"¦§¦¡¦«¦¡¦«¦¡¦©"},
	{"¦¢  ¦¢  ¦¢  ¦¢"},
	{"¦§¦¡¦«¦¡¦«¦¡¦©"},
	{"¦¢  ¦¢  ¦¢  ¦¢"},
	{"¦¦¦¡¦ª¦¡¦ª¦¡¦¥"},
};
int map[3][3] = { {9,9,9,}, {9,9,9}, {9,9,9}};
int mapX, mapY;

int dispMap(){
	gotoXY(0, 21); printf("%d %d %d", map[0][0],map[0][1],map[0][2]);
	gotoXY(0, 22); printf("%d %d %d", map[1][0],map[1][1],map[1][2]);
	gotoXY(0, 23); printf("%d %d %d", map[2][0],map[2][1],map[2][2]);
	gotoXY(40, 23); printf("mapXY[%d %d]", mapY, mapX);
	gotoXY(playerX, playerY);
}

void check(){
	
	if(map[0][0]+map[0][1]+map[0][2]+map[1][0]+map[1][1]+map[1][2]+map[2][0]+map[2][1]+map[2][2]<=9){
		gotoXY(30,18); printf("¡¿,¡Ûdraw");
	}
	for(int y = 0; y < 3; y++){
		if(map[y][0] + map[y][1] + map[y][2] == 3){
			gotoXY(30,18); printf("¡¿ win!,¡Û lose");
			Sleep(1000);
			exit(0);
			//X win
		}	
		if(map[y][0] + map[y][1] + map[y][2] == 0){
			gotoXY(30,18); printf("¡Û win!,¡¿ lose");
			Sleep(1000);
			exit(0);
			//O win
		}
	}
	for(int x = 0; x < 3; x++){
		if(map[0][x] + map[1][x] + map[2][x] == 3){
			gotoXY(30,18); printf("¡¿ win!,¡Û lose");
			Sleep(1000);
			exit(0);
			//X win
		}
		if(map[0][x] + map[1][x] + map[2][x] == 0){
			gotoXY(30,18); printf("¡Û win!,¡¿ lose");
			Sleep(1000);
			exit(0);
			//O win
		}
	}
	if(map[0][0]+map[1][1]+map[2][2] == 0) {
		gotoXY(30,18); printf("¡Û win!,¡¿ lose");
		Sleep(1000);
		exit(0);
	}
	if(map[0][0]+map[1][1]+map[2][2] == 3) {
		gotoXY(30,18); printf("¡¿ win!,¡Û lose");
		Sleep(1000);
		exit(0);
	}
	if(map[0][2]+map[1][1]+map[2][0] == 0) {
		gotoXY(30,18); printf("¡Û win!,¡¿ lose");
		Sleep(1000);
		exit(0);
	}
	if(map[0][2]+map[1][1]+map[2][0] == 3) {
		gotoXY(30,18); printf("¡¿ win!,¡Û lose");
		Sleep(1000);
		exit(0);
	}
}

void com(){
	int x,y;
	do{
		x = rand() % 3;
		y = rand() % 3;
	} while(map[y][x] != 9);
	map[y][x] = 1;
	gotoXY((boardX+2)+x*4, boardY+1+y*2); puts("¡¿");
	gotoXY((boardX+2)+x*4, boardY+1+y*2);
	status = status * -1;
}

int main() {
	init(80, 25, 1);
	system("cls");
	dispTitle();
	dispBoard();
	
	playerX = boardX + 6;
	playerY = boardY + 3;
	mapX = 1;
	mapY = 1;
	gotoXY(playerX, playerY);
	
	while(1) {
		ch = keyInput();
		switch(ch){
			case LEFT:
				playerX = playerX -4;
				mapX = mapX - 1;
				if(playerX <boardX + 2){
					playerX = playerX + 12;
					mapX = 2;
				}
				gotoXY(playerX, playerY);
				break;
			case RIGHT:
				playerX = playerX +4;
				mapX = mapX +1;
				if(playerX >boardX + 10){
					playerX = playerX - 12;
					mapX = 0;
				}
				gotoXY(playerX, playerY);
				break;
			case UP:
				playerY = playerY -2;
				mapY = mapY -1;
				if(playerY <boardY + 1){
					playerY = playerY + 6;
					mapY = 2;
				}
				gotoXY(playerX, playerY);
				break;
			case DOWN:
				playerY = playerY +2;
				mapY = mapY +1;
				if(playerY >boardY + 5){
					playerY = playerY - 6;
					mapY = 0;
				}
				gotoXY(playerX, playerY);
				break;
			case SPACE:
				//gotoXY(plater,player)
				if(map[mapY][mapX] == 9){
					if(status == 1){
						map[mapY][mapX] = 0;
						puts("¡Û");
					}
					else{
						map[mapY][mapX] = 1;
						puts("¡¿");
					}
					status = status * -1;
					gotoXY(playerX, playerY);
					//check();
					//com();
					check();
				}
				else{
					if(map[mapY][mapX] == 0){
						setColor(14, 4); gotoXY(playerX, playerY); printf("¡Û"); //puts("¡Û"); °¡´É 
						Sleep(100);
						setColor(14, 4); gotoXY(playerX, playerY); printf(" ");
						Sleep(100);
						setColor(14, 4); gotoXY(playerX, playerY); printf("¡Û");
						Sleep(100);
						gotoXY(playerX, playerY);
					}
				}
				break;
			case ESC:
				return 0;
		} //end of switch(ch)
		dispMap();
	} //end of while(1)
	return 0;	
}

void dispBoard() {
	for(int i = 0; i < 7; i++) {
		gotoXY(boardX, boardY + i);
		puts(board[i]);
	}
}

void dispTitle() {
	for(int i = 0; i < 5; i++)	{
		gotoXY(titleX, titleY + i);
		puts(title[i]);
	}
}
