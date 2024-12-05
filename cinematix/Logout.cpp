// logout.cpp
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "bioskop.h"

// Deklarasi fungsi
int Logout();

int Logout(){
    system("color 8");	
    int r, q;
    printf("Logging out ...\n");
    for(r = 1; r <= 20; r++){
        for(q = 0; q < 10000000; q++); // Simulasi loading
        printf("%c", 177);
    }
    printf("\n");
    system("cls");
    return 0;
} 

