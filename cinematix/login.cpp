// login.cpp
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "bioskop.h"

// Fungsi Login
int login(){
    FILE *file;
    char inputUser[50], inputPass[50];
    char storedUser[50], storedPass[50], role[10];
    int found = 0;

    system("cls");
    printf("======== Login Cinemaxxx ========\n\n");
    printf("Username: ");
    scanf("%s", inputUser);
    printf("Password: ");
    scanf("%s", inputPass);
    fflush(stdin);

    file = fopen("password.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file password.txt\n");
        getch();
        return 0;
    }

    while(fscanf(file, "%s %s %s", storedUser, storedPass, role) != EOF){
        if(strcmp(inputUser, storedUser) == 0 && strcmp(inputPass, storedPass) == 0){
            printf("Login berhasil sebagai %s!\n", role);
            fclose(file);
            getch();
            // Kembalikan status berdasarkan role
            if(strcmp(role, "ADMIN") == 0){
                return 1; // Admin
            }
            else{
                return 2; // User
            }
        }
    }

    fclose(file);
    printf("Username atau Password salah!\n");
    getch();
    return 0;
}

