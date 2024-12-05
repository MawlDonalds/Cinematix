// register.cpp
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "bioskop.h"

// Deklarasi fungsi
int registerUser();

int registerUser(){
    FILE *file;
    Account newUser;
    
    system("cls");
    printf("\n\n\n\t\t\t-----------------------------\n");
    printf("\t\t\t|       Registrasi USER     |\n");
    printf("\t\t\t-----------------------------\n\n");
    printf("\t\t\tUsername : ");
    scanf("%19s", newUser.username);
    printf("\t\t\tPassword : ");
    scanf("%19s", newUser.password);
    strcpy(newUser.role, "USER"); // Pastikan role adalah USER

    // Simpan ke file
    file = fopen("password.txt", "a");
    if(file == NULL){
        printf("Gagal membuka file password.txt\n");
        getch();
        return 0;
    }
    fprintf(file, "%s %s %s\n", newUser.username, newUser.password, newUser.role);
    fclose(file);

    printf("\nRegistrasi berhasil! Silakan login.");
    getch();
    return 0;
}

