// admin.cpp
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "bioskop.h"

// Deklarasi fungsi
int adminMenu();
int editFilm();
int editJamTayang();
int editStudio();
int editHarga();
int lihatRiwayat();
int editTempatDuduk();

int adminMenu(){
    int pilihan;
    while (1) {
        system("cls");
        printf("=========================================================================\n");
        printf("\t\t\t Menu ADMIN FunCinema \n");
        printf("=========================================================================\n\n");
        printf("\t1. Edit Film\n");
        printf("\t2. Edit Jam Tayang\n");
        printf("\t3. Edit Studio\n");
        printf("\t4. Edit Harga Tiket\n");
        printf("\t5. Lihat Riwayat Pemesanan\n");
        printf("\t6. Edit Tempat Duduk\n");
        printf("\t7. Logout\n");
        printf("=========================================================================\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch (pilihan) {
            case 1:
                editFilm();
                break;
            case 2:
                editJamTayang();
                break;
            case 3:
                editStudio();
                break;
            case 4:
                editHarga();
                break;
            case 5:
                lihatRiwayat();
                break;
            case 6:
                editTempatDuduk();
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

int editFilm(){
    FILE *file;
    Show sh;
    int filmNumber;
    
    system("cls");
    printf("======== Edit Film ========\n");
    printf("Daftar Film:\n");
    for(int i = 1; i < 5; i++){
        printf("%d. %s\n", i, sh.jud[i]);
    }
    printf("Pilih nomor film yang ingin diubah (1-4): ");
    scanf("%d", &filmNumber);
    fflush(stdin);
    
    if(filmNumber < 1 || filmNumber > 4){
        printf("Nomor film tidak valid!\n");
        getch();
        return 0;
    }
    
    printf("Masukkan nama film baru: ");
    scanf("%49s", sh.jud[filmNumber]);
    
    // Simpan perubahan ke file atau variabel global jika ada
    // Implementasikan penyimpanan sesuai kebutuhan
    
    printf("Film berhasil diubah!\n");
    getch();
    return 0;
}

int editJamTayang(){
    Show sh;
    int filmNumber, jamNumber;
    float newJam;

    system("cls");
    printf("======== Edit Jam Tayang ========\n");
    printf("Daftar Film:\n");
    for(int i = 1; i < 5; i++){
        printf("%d. %s\n", i, sh.jud[i]);
    }
    printf("Pilih nomor film yang ingin diubah jam tayangnya (1-4): ");
    scanf("%d", &filmNumber);
    fflush(stdin);

    if(filmNumber < 1 || filmNumber > 4){
        printf("Nomor film tidak valid!\n");
        getch();
        return 0;
    }

    printf("Daftar Jam Tayang untuk %s:\n", sh.jud[filmNumber]);
    for(int i = 1; i <=6; i++){
        if(filmNumber ==1 || filmNumber ==4){
            printf("%d. %.2f\n", i, sh.jamx[i]);
        }
        else{
            printf("%d. %.2f\n", i, sh.jamy[i]);
        }
    }
    printf("Pilih jam ke yang ingin diubah (1-6): ");
    scanf("%d", &jamNumber);
    fflush(stdin);

    if(jamNumber < 1 || jamNumber >6){
        printf("Nomor jam tidak valid!\n");
        getch();
        return 0;
    }

    printf("Masukkan jam baru (contoh: 18.30): ");
    scanf("%f", &newJam);
    fflush(stdin);

    if(filmNumber ==1 || filmNumber ==4){
        sh.jamx[jamNumber] = newJam;
    }
    else{
        sh.jamy[jamNumber] = newJam;
    }

    // Simpan perubahan ke file atau variabel global jika ada
    // Implementasikan penyimpanan sesuai kebutuhan

    printf("Jam tayang berhasil diubah!\n");
    getch();
    return 0;
}

int editStudio(){
    // Implementasikan sesuai kebutuhan
    // Misalnya, mengubah jumlah studio, nama studio, dll.
    printf("Fitur ini sedang dalam pengembangan.\n");
    getch();
    return 0;
}

int editHarga(){
    Show sh;
    Nonton dt;
    int pilihan;
    
    system("cls");
    printf("======== Edit Harga Tiket ========\n");
    printf("1. Harga Weekday\n");
    printf("2. Harga Weekend\n");
    printf("Pilih opsi yang ingin diubah: ");
    scanf("%d", &pilihan);
    fflush(stdin);

    switch(pilihan){
        case 1:
            printf("Masukkan harga tiket baru untuk Weekday: Rp. ");
            scanf("%f", &dt.hargatiket_weekday);
            // Simpan perubahan ke file atau variabel global
            printf("Harga Weekday berhasil diubah!\n");
            break;
        case 2:
            printf("Masukkan harga tiket baru untuk Weekend: Rp. ");
            scanf("%f", &dt.hargatiket_weekend);
            // Simpan perubahan ke file atau variabel global
            printf("Harga Weekend berhasil diubah!\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
    }
    getch();
    return 0;
}

int lihatRiwayat(){
    FILE *Tickets = fopen("Report.txt", "r");
    char buffer[256];
    system("cls");
    printf("======== Riwayat Pemesanan ========\n\n");
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

int editTempatDuduk(){
    // Implementasikan sesuai kebutuhan
    // Misalnya, mengubah layout kursi, status kursi (terisi atau tidak), dll.
    printf("Fitur ini sedang dalam pengembangan.\n");
    getch();
    return 0;
}

