// main.cpp
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "bioskop.h"

// Deklarasi fungsi login dan register
int login();
int registerUser();

int main(){
    int pilihan;
    while(1){
        system("cls");
        printf("=========================================================================\n");
        printf("\t\t\t Cinemaxxx \n");
        printf("=========================================================================\n\n");
        printf("\t1. Login\n");
        printf("\t2. Register\n");
        printf("\t3. Exit\n");
        printf("=========================================================================\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch(pilihan){
            case 1:
                {
                    int role = login();
                    if(role == 1){
                        // Admin
                        adminMenu();
                    }
                    else if(role == 2){
                        // User
                        userMenu();
                    }
                    break;
                }
            case 2:
                registerUser();
                break;
            case 3:
                printf("Terimakasih telah menggunakan Cinemaxx!\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
                getch();
        }
    }
    return 0;
} 

