// Logout.cpp
#include <stdio.h>    // Untuk printf()
#include <stdlib.h>   // Untuk system()
#include <conio.h>    // Untuk getch()
#include "bioskop.h"  // Untuk deklarasi fungsi dan struktur data

int Logout(){
    system("cls"); // Membersihkan layar (Windows)
    printf("Anda telah berhasil logout.\n");
    printf("Tekan sembarang key untuk kembali ke menu utama...");
    getch(); // Menunggu input key tanpa menampilkan karakter
    return 0;
}

