#include <windows.h>
#include <conio.h>

//CUI �⺻ Ű 
#define ENTER 13
#define ESC 27
#define SPACE 32
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

//CUI �⺻ �Լ�  
void init(int cols, int lines, int cursorShow) {
	char str[80] = "";
	sprintf(str, "mode con cols=%d lines=%d  | title Console Game", cols, lines);
	system(str);	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	
	CONSOLE_CURSOR_INFO consoleCursor;	// �ܼ�Ŀ�� ���� ����ü
	consoleCursor.bVisible = 0;
	consoleCursor.dwSize = cursorShow;       //100�� �ִ밪 
	SetConsoleCursorInfo(consoleHandle, &consoleCursor);
	
	system("color F0"); //���� �����  	
	system("cls");	
}

int keyInput() {
	int key;
	key = getch();
	if(key == 0 || key == 0xE0) {
		key = getch();
	}
	return key;
}

void gotoXY(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	
	position.X = x;
	position.Y = y;
	
	SetConsoleCursorPosition(consoleHandle, position);
}

//�� �Ӽ��� 2�ڸ� 16������ ����, ù° �ڸ��� ����, ��° �ڸ��� ���ڻ�
//��ο� �� : 0:����, 1:�Ķ�,  2:���,  3: �ϴ�,   4:����,  5:����   6:���,  7:ȸ�� 
//���� ��   : 8:ȸ��, 9:�Ķ�, 10:���, 11:�ϴû�, 12:����, 13:��ȫ, 14:���, 15:���  

//�ؽ�Ʈ�� ���� ���� 
void setColor(int bgColor, int textColor) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hconsole, (bgColor << 4) | textColor);
}

//�ؽ�Ʈ �� ����  
void setTextColor(int textColor) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes&0xf0) | (textColor&0xf));
}

//��� �� ���� 
void setBgColor(int bgcolor){
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgcolor&0xf)<<4) | (info.wAttributes&0xf));
} 

//�ؽ�Ʈ �� ȹ��  
int getTextColor() {
   CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return info.wAttributes&0xf;
}

//���� ȹ�� 
int getBgColor() {
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return (info.wAttributes&0xf0)>>4;
}

int whereX(void) {
  HANDLE hCon;
  CONSOLE_SCREEN_BUFFER_INFO sInfo;

  hCon = GetStdHandle(STD_OUTPUT_HANDLE);

  GetConsoleScreenBufferInfo(hCon, &sInfo);

  return (int) sInfo.dwCursorPosition.X;
}

int whereY(void) {
  HANDLE hCon;
  CONSOLE_SCREEN_BUFFER_INFO sInfo;

  hCon = GetStdHandle(STD_OUTPUT_HANDLE);

  GetConsoleScreenBufferInfo(hCon, &sInfo);
  return (int) sInfo.dwCursorPosition.Y;
}

void cls(int bgColor, int textColor) {
  COORD coordScreen = {0, 0 };
  DWORD dwCnt;
  HANDLE hCon;

  hCon = GetStdHandle(STD_OUTPUT_HANDLE);

  FillConsoleOutputCharacter(hCon, ' ', 24000, coordScreen, &dwCnt);
  FillConsoleOutputAttribute(hCon, (bgColor << 4) + textColor, 24000, coordScreen, &dwCnt);

  SetConsoleCursorPosition(hCon, coordScreen);

  setColor(bgColor, textColor);
}
