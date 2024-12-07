// main.cpp
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include "bioskop.h"

// Deklarasi fungsi eksternal
extern int getLogin();
extern int registerUser();
extern int adminMenu();
extern int userMenu();

int main() {
    int pilihan;
    while (1) {
        system("cls");
        printf("=========================================================================\n");
        printf("\t\t\t FunCinema \n");
        printf("=========================================================================\n\n");
        printf("\t\t\t1. Login\n");
        printf("\t\t\t2. Register\n");
        printf("\t\t\t3. Keluar\n");
        printf("=========================================================================\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch (pilihan) {
            case 1: {
                int role = getLogin();
                if (role == 1) { // ADMIN
                    adminMenu();
                }
                else { // USER
                    userMenu();
                }
                break;
            }
            case 2:
                registerUser();
                break;
            case 3:
                printf("Terimakasih telah menggunakan aplikasi FunCinema!\n");
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
                getch();
        }
    }
    return 0;
} 

