#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "bioskop.h"

// Deklarasi fungsi
int userMenu();
int pilihHari();
int pilihFilm();
int pilihJam();
int pilihKursi();
int cetakTiket();
int bayarTiket();

int userMenu(){
    int pilihan;
    while (1) {
        system("cls");
        printf("=========================================================================\n");
        printf("\t\t\t Menu USER FunCinema \n");
        printf("=========================================================================\n\n");
        printf("\t1. Pilih Hari\n");
        printf("\t2. Pilih Film\n");
        printf("\t3. Pilih Jam\n");
        printf("\t4. Pilih Tempat Duduk\n");
        printf("\t5. Cetak Tiket\n");
        printf("\t6. Bayar\n");
        printf("\t7. Logout\n");
        printf("=========================================================================\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch (pilihan) {
            case 1:
                pilihHari();
                break;
            case 2:
                pilihFilm();
                break;
            case 3:
                pilihJam();
                break;
            case 4:
                pilihKursi();
                break;
            case 5:
                cetakTiket();
                break;
            case 6:
                bayarTiket();
                break;
            case 7:
                Logout();
                return 0; // Kembali ke main menu tanpa menutup program
            default:
                printf("Pilihan tidak valid!\n");
                getch();
        }
    }
    return 0;
}

int pilihHari(){
    // Implementasikan fitur pemilihan hari
    printf("Fitur ini sedang dalam pengembangan.\n");
    getch();
    return 0;
}

int pilihFilm(){
    // Implementasikan fitur pemilihan film
    printf("Fitur ini sedang dalam pengembangan.\n");
    getch();
    return 0;
}

int pilihJam(){
    // Implementasikan fitur pemilihan jam
    printf("Fitur ini sedang dalam pengembangan.\n");
    getch();
    return 0;
}

int pilihKursi(){
    // Implementasikan fitur pemilihan kursi
    printf("Fitur ini sedang dalam pengembangan.\n");
    getch();
    return 0;
}

int cetakTiket(){
    // Implementasikan fitur cetak tiket
    printf("Fitur ini sedang dalam pengembangan.\n");
    getch();
    return 0;
}

int bayarTiket(){
    // Implementasikan fitur pembayaran tiket
    printf("Fitur ini sedang dalam pengembangan.\n");
    getch();
    return 0;
}

