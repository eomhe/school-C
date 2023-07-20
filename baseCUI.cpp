#include <windows.h>
#include <conio.h>

//CUI 기본 키 
#define ENTER 13
#define ESC 27
#define SPACE 32
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

//CUI 기본 함수  
void init(int cols, int lines, int cursorShow) {
	char str[80] = "";
	sprintf(str, "mode con cols=%d lines=%d  | title Console Game", cols, lines);
	system(str);	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	
	CONSOLE_CURSOR_INFO consoleCursor;	// 콘솔커서 정보 구조체
	consoleCursor.bVisible = 0;
	consoleCursor.dwSize = cursorShow;       //100이 최대값 
	SetConsoleCursorInfo(consoleHandle, &consoleCursor);
	
	system("color F0"); //배경색 전경색  	
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

//색 속성은 2자리 16진수로 결정, 첫째 자리는 배경색, 둘째 자리는 문자색
//어두운 색 : 0:검정, 1:파랑,  2:녹색,  3: 하늘,   4:빨강,  5:보라   6:노랑,  7:회색 
//밝은 색   : 8:회색, 9:파랑, 10:녹색, 11:하늘색, 12:빨강, 13:분홍, 14:노랑, 15:흰색  

//텍스트색 배경색 변경 
void setColor(int bgColor, int textColor) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hconsole, (bgColor << 4) | textColor);
}

//텍스트 색 변경  
void setTextColor(int textColor) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes&0xf0) | (textColor&0xf));
}

//배경 색 변경 
void setBgColor(int bgcolor){
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgcolor&0xf)<<4) | (info.wAttributes&0xf));
} 

//텍스트 색 획득  
int getTextColor() {
   CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return info.wAttributes&0xf;
}

//배경색 획득 
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
