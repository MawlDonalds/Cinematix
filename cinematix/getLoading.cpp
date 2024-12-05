#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "bioskop.h"

void gotoxy(int x,int y){
	COORD coord;
	coord.X=x;
		coord.Y=y;
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
}

int getLoading(){
	system("color 8");	
	int r,q;
	gotoxy(35,16);
	printf("Dashboard is now loading...");
	gotoxy(35,18);
	for(r=1;r<=20;r++){
		for(q=0;q<100000000;q++);
		printf("%c",177);
	}
}
