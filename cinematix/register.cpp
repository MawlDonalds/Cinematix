// register.cpp
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "bioskop.h"

// Deklarasi fungsi
int registerUser();

int registerUser(){
    char username[20];
    char password[20];
    char role[10] = "USER"; // Default role adalah USER

    system("cls");
    printf("=========================================================================\n");
    printf("\t\t\t Register User FunCinema \n");
    printf("=========================================================================\n\n");
    printf("Username: ");
    scanf("%19s", username);
    printf("Password: ");
    scanf("%19s", password);
    fflush(stdin);

    // Simpan data ke file password.txt
    FILE *file = fopen("password.txt", "a");
    if(file == NULL){
        printf("Gagal membuka file password.txt\n");
        getch();
        return 1;
    }

    fprintf(file, "%s %s %s\n", username, password, role);
    fclose(file);

    printf("Registrasi berhasil! Silakan login dengan akun Anda.\n");
    getch();
    return 0;
}

