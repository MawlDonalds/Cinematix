// menu.cpp
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include "bioskop.h"

// Implementasi fungsi getLogin
int getLogin(){
    int role = login();
    if(role == 1){
        // Admin
        adminMenu();
    }
    else if(role == 2){
        // User
        userMenu();
    }
    else{
        // Login gagal atau peran tidak dikenal
        printf("Login gagal atau peran tidak dikenal.\n");
        getch();
    }
    return 0;
}

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
                getLogin(); // Memanggil getLogin() untuk kembali ke login
                break;
            }
            case 5 : { 
                printf("\n\n Terima Kasih... :) ");
                exit(1);
            }
            default : { 
                printf("\n\n Pilihan tidak valid! Terima Kasih... :) ");
                exit(1);
            }
        }
    }
} 

