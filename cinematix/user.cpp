// user.cpp
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "bioskop.h"

// Deklarasi fungsi User
int userMenu();
int beliTiket();
int lihatFilm();
int lihatRiwayatUser();

// Implementasi fungsi userMenu()
int userMenu(){
    int pilihan;
    while(1){
        system("cls");
        printf("=========================================================================\n");
        printf("\t\t\t Menu  Cinemaxxx \n");
        printf("=========================================================================\n\n");
        printf("\t1. Lihat Film\n");
        printf("\t2. Beli Tiket\n");
        printf("\t3. Lihat Riwayat Pemesanan\n");
        printf("\t4. Logout\n");
        printf("=========================================================================\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch(pilihan){
            case 1:
                lihatFilm();
                break;
            case 2:
                beliTiket();
                break;
            case 3:
                lihatRiwayatUser();
                break;
            case 4:
                Logout();
                return 0; // Kembali ke main menu tanpa menutup program
            default:
                printf("Pilihan tidak valid!\n");
                getch();
        }
    }
    return 0;
}

// Implementasi fungsi lihatFilm()
int lihatFilm(){
    FILE *file;
    Show sh;
    int filmNumber;

    system("cls");
    printf("======== Daftar Film ========\n\n");

    file = fopen("films.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file films.txt\n");
        getch();
        return 0;
    }

    printf("No.\tFilm\n");
    printf("-------------------------\n");
    while(fscanf(file, "%d %s", &sh.filmID, sh.judul) != EOF){
        printf("%d.\t%s\n", sh.filmID, sh.judul);
    }
    fclose(file);

    printf("\nPress any key to kembali...");
    getch();
    return 0;
}

// Implementasi fungsi beliTiket()
int beliTiket(){
    // Panggil fungsi getBioskop() untuk memulai proses pembelian tiket
    getBioskop();
    return 0;
}

// Implementasi fungsi lihatRiwayatUser()
int lihatRiwayatUser(){
    FILE *Tickets = fopen("Report.txt", "r");
    char buffer[256];
    system("cls");
    printf("======== Riwayat Pemesanan Anda ========\n\n");
    if (!Tickets){
        printf("Tidak ada riwayat pemesanan.\n");
    }
    else{
        while(fgets(buffer, sizeof(buffer), Tickets)){
            printf("%s", buffer);
        }
        fclose(Tickets);
    }
    printf("\nPress any key to kembali...");
    getch();
    return 0;
}

