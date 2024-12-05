// login.cpp
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "bioskop.h"

// Deklarasi fungsi
int login();
void selesai();

int getLogin(){
    return login();
}

int login(){
    char input_user[20];
    char input_pass[20];
    Account acc;
    int is_admin = 0;
    int found = 0;

    while(1) { // Loop terus hingga login berhasil
        system("cls"); // Bersihkan layar sebelum menampilkan prompt login
        system("color 7");	
        printf("\n\n\n\n\t\t\t--------------------------\n");
        printf("\t\t\t| Aplikasi FunCinema |\n");
        printf("\t\t\t--------------------------\n\n");
        printf("\t\t\t Menu Login\n");
        printf("\t\t\t Username : ");
        scanf("%19s", input_user); // Batasi input untuk menghindari buffer overflow
    
        printf("\t\t\t Password : ");
        scanf("%19s", input_pass);	

        // Buka file password.txt
        FILE *file = fopen("password.txt", "r");
        if(file == NULL){
            printf("Gagal membuka file password.txt\n");
            getch();
            exit(1);
        }

        found = 0;
        is_admin = 0;

        // Baca setiap baris dan bandingkan dengan input
        while(fscanf(file, "%19s %19s %9s", acc.username, acc.password, acc.role) != EOF){
            if(strcmp(input_user, acc.username) == 0 && strcmp(input_pass, acc.password) == 0){
                found = 1;
                if(strcmp(acc.role, "ADMIN") == 0){
                    is_admin = 1;
                }
                break;
            }
        }

        fclose(file);

        if(found){
            if(is_admin){
                printf("\nLogin sebagai ADMIN berhasil!\n");
                getch();
                return 1; // ADMIN
            }
            else{
                printf("\nLogin sebagai USER berhasil! Selamat datang, %s.\n", input_user);
                getch();
                return 0; // USER
            }
        }
        else{
            printf("\nUsername atau Password yang Anda masukkan salah!\n");
            printf("Silakan coba lagi.\n");
            getch();
            // Loop akan kembali ke awal dan membersihkan layar
        }
    }
    
    // Fungsi ini tidak akan pernah mencapai sini karena loop berjalan terus hingga login berhasil
    return 0;
}

void selesai(){
    printf("\n\n\n\t\t\t Login Sukses, Selamat datang!");
    // getLoading(); // Implementasikan jika ada
    getch();
} 

