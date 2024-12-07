// menu.cpp
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include "bioskop.h"

// Implementasi fungsi menu admin jika diperlukan
// Berikut adalah contoh sederhana
int menu() {
    system("cls");
    system("color 7");	
    printf("=========================================================================\n");
    printf("\t\t\t FunCinema - Admin Menu \n");
    printf("=========================================================================\n\n");
    int pil = 0;
    for (;;)
    {
        printf("\t Menu : \n");
        printf("\t\t 1. Beli Tiket \n");
        printf("\t\t 2. Tampil isi file \n");
        printf("\t\t 3. Hapus isi file \n");
        printf("\t\t 4. Log out \n");
        printf("\t\t 5. Terminate aplikasi \n");
        printf("\n\t Pilihan : "); 
        scanf("%d", &pil);

        switch (pil){
            case 1 : { 
                system("cls");
                getBioskop();
                break; 
            }
            case 2 : { 
                system("cls");
                Tampil_Lihat();
                break; 
            }
            case 3 : { 
                system("cls");
                Delete();
                break; 
            }
            case 4 : {
                system("cls");
                Logout();
                system("cls");
                system("color 7");	
                getLogin();
                break;
            }
            default : { 
                printf("\n\n Terima Kasih... :) ");
                exit(1);
            }
        }
    }
}

