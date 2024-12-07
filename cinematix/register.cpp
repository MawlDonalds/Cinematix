// register.cpp
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "bioskop.h"

// Fungsi Register
int registerUser(){
    FILE *file;
    char newUser[50], newPass[50];
    char confirmPass[50];

    system("cls");
    printf("======== Register FunCinema ========\n\n");
    printf("Username baru: ");
    scanf("%s", newUser);
    printf("Password baru: ");
    scanf("%s", newPass);
    printf("Konfirmasi Password: ");
    scanf("%s", confirmPass);
    fflush(stdin);

    if(strcmp(newPass, confirmPass) != 0){
        printf("Password tidak cocok!\n");
        getch();
        return 0;
    }

    // Menambahkan user ke file password.txt dengan role USER
    file = fopen("password.txt", "a");
    if(file == NULL){
        printf("Gagal membuka file password.txt\n");
        getch();
        return 0;
    }

    fprintf(file, "%s %s USER\n", newUser, newPass);
    fclose(file);

    printf("Registrasi berhasil! Anda dapat login sekarang.\n");
    getch();
    return 1;
}

