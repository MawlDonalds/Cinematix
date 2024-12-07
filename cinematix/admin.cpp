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

// Fungsi Logout
//int Logout(){
//    system("cls");
//    printf("Anda telah berhasil logout.\n");
//    printf("Tekan sembarang key untuk kembali ke menu utama...");
//    getch();
//    return 0;
//}

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

    // Tampilkan daftar film
    file = fopen("films.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file films.txt\n");
        getch();
        return 0;
    }

    printf("Daftar Film:\n");
    while(fscanf(file, "%d %s", &sh.filmID, sh.judul) != EOF){
        printf("%d. %s\n", sh.filmID, sh.judul);
    }
    fclose(file);

    printf("Pilih nomor film yang ingin diubah (1-4): ");
    scanf("%d", &filmNumber);
    fflush(stdin);

    if(filmNumber < 1 || filmNumber > 4){
        printf("Nomor film tidak valid!\n");
        getch();
        return 0;
    }

    printf("Masukkan nama film baru: ");
    scanf("%49s", sh.judul);
    fflush(stdin);

    // Membaca semua film ke dalam array
    Show films[5];
    file = fopen("films.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file films.txt\n");
        getch();
        return 0;
    }
    int i = 0;
    while(fscanf(file, "%d %s", &films[i].filmID, films[i].judul) != EOF && i < 4){
        i++;
    }
    fclose(file);

    // Mengubah nama film yang dipilih
    strcpy(films[filmNumber-1].judul, sh.judul);

    // Menulis kembali ke file
    file = fopen("films.txt", "w");
    if(file == NULL){
        printf("Gagal membuka file films.txt untuk menulis\n");
        getch();
        return 0;
    }
    for(int j = 0; j < 4; j++){
        fprintf(file, "%d %s\n", films[j].filmID, films[j].judul);
    }
    fclose(file);

    printf("Film berhasil diubah!\n");
    getch();
    return 0;
}

int editJamTayang(){
    FILE *fileFilm, *fileShow;
    Show sh;
    int filmNumber, jamNumber;
    float newJam;

    system("cls");
    printf("======== Edit Jam Tayang ========\n");

    // Tampilkan daftar film
    fileFilm = fopen("films.txt", "r");
    if(fileFilm == NULL){
        printf("Gagal membuka file films.txt\n");
        getch();
        return 0;
    }

    printf("Daftar Film:\n");
    while(fscanf(fileFilm, "%d %s", &sh.filmID, sh.judul) != EOF){
        printf("%d. %s\n", sh.filmID, sh.judul);
    }
    fclose(fileFilm);

    printf("Pilih nomor film yang ingin diubah jam tayangnya (1-4): ");
    scanf("%d", &filmNumber);
    fflush(stdin);

    if(filmNumber < 1 || filmNumber > 4){
        printf("Nomor film tidak valid!\n");
        getch();
        return 0;
    }

    // Tampilkan jam tayang untuk film yang dipilih
    printf("Daftar Jam Tayang untuk film nomor %d:\n", filmNumber);
    fileShow = fopen("showtimes.txt", "r");
    if(fileShow == NULL){
        printf("Gagal membuka file showtimes.txt\n");
        getch();
        return 0;
    }

    printf("Jam Tayang:\n");
    while(fscanf(fileShow, "%d %d %f", &sh.filmID, &jamNumber, &newJam) != EOF){
        if(sh.filmID == filmNumber){
            printf("%d. %.2f\n", jamNumber, newJam);
        }
    }
    fclose(fileShow);

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

    // Membaca semua showtimes ke dalam array menggunakan variabel sementara
    struct ShowTime {
        int filmID;
        int jamNumber;
        float jamTime;
    } showtimes[100]; // Asumsikan maksimal 100 showtimes

    int count = 0;
    fileShow = fopen("showtimes.txt", "r");
    if(fileShow == NULL){
        printf("Gagal membuka file showtimes.txt\n");
        getch();
        return 0;
    }
    while(fscanf(fileShow, "%d %d %f", &showtimes[count].filmID, &showtimes[count].jamNumber, &showtimes[count].jamTime) != EOF && count < 100){
        count++;
    }
    fclose(fileShow);

    // Mengubah jam tayang yang dipilih
    for(int j = 0; j < count; j++){
        if(showtimes[j].filmID == filmNumber && showtimes[j].jamNumber == jamNumber){
            showtimes[j].jamTime = newJam;
            break;
        }
    }

    // Menulis kembali ke file
    fileShow = fopen("showtimes.txt", "w");
    if(fileShow == NULL){
        printf("Gagal membuka file showtimes.txt untuk menulis\n");
        getch();
        return 0;
    }
    for(int j = 0; j < count; j++){
        fprintf(fileShow, "%d %d %.2f\n", showtimes[j].filmID, showtimes[j].jamNumber, showtimes[j].jamTime);
    }
    fclose(fileShow);

    printf("Jam tayang berhasil diubah!\n");
    getch();
    return 0;
}

int editStudio(){
    FILE *file;
    Studio studio;
    int studioNumber;

    system("cls");
    printf("======== Edit Studio ========\n");

    // Tampilkan daftar studio
    file = fopen("studios.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file studios.txt\n");
        getch();
        return 0;
    }

    printf("Daftar Studio:\n");
    while(fscanf(file, "%d %s", &studio.studioID, studio.namaStudio) != EOF){
        printf("%d. %s\n", studio.studioID, studio.namaStudio);
    }
    fclose(file);

    printf("Pilih nomor studio yang ingin diubah (1-4): ");
    scanf("%d", &studioNumber);
    fflush(stdin);

    if(studioNumber < 1 || studioNumber > 4){
        printf("Nomor studio tidak valid!\n");
        getch();
        return 0;
    }

    printf("Masukkan nama studio baru: ");
    scanf("%49s", studio.namaStudio);
    fflush(stdin);

    // Membaca semua studio ke dalam array
    Studio studios[5];
    file = fopen("studios.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file studios.txt\n");
        getch();
        return 0;
    }
    int i = 0;
    while(fscanf(file, "%d %s", &studios[i].studioID, studios[i].namaStudio) != EOF && i < 4){
        i++;
    }
    fclose(file);

    // Mengubah nama studio yang dipilih
    strcpy(studios[studioNumber-1].namaStudio, studio.namaStudio);

    // Menulis kembali ke file
    file = fopen("studios.txt", "w");
    if(file == NULL){
        printf("Gagal membuka file studios.txt untuk menulis\n");
        getch();
        return 0;
    }
    for(int j = 0; j < 4; j++){
        fprintf(file, "%d %s\n", studios[j].studioID, studios[j].namaStudio);
    }
    fclose(file);

    printf("Studio berhasil diubah!\n");
    getch();
    return 0;
}

int editHarga(){
    FILE *file;
    float weekdayPrice, weekendPrice;
    int pilihan;

    system("cls");
    printf("======== Edit Harga Tiket ========\n");
    printf("1. Harga Weekday\n");
    printf("2. Harga Weekend\n");
    printf("Pilih opsi yang ingin diubah: ");
    scanf("%d", &pilihan);
    fflush(stdin);

    // Membaca harga saat ini
    file = fopen("prices.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file prices.txt\n");
        getch();
        return 0;
    }
    fscanf(file, "%f %f", &weekdayPrice, &weekendPrice);
    fclose(file);

    switch(pilihan){
        case 1:
            printf("Masukkan harga tiket baru untuk Weekday: Rp. ");
            scanf("%f", &weekdayPrice);
            fflush(stdin);
            break;
        case 2:
            printf("Masukkan harga tiket baru untuk Weekend: Rp. ");
            scanf("%f", &weekendPrice);
            fflush(stdin);
            break;
        default:
            printf("Pilihan tidak valid!\n");
            getch();
            return 0;
    }

    // Menulis kembali ke file
    file = fopen("prices.txt", "w");
    if(file == NULL){
        printf("Gagal membuka file prices.txt untuk menulis\n");
        getch();
        return 0;
    }
    fprintf(file, "%.2f %.2f\n", weekdayPrice, weekendPrice);
    fclose(file);

    if(pilihan == 1){
        printf("Harga Weekday berhasil diubah!\n");
    }
    else{
        printf("Harga Weekend berhasil diubah!\n");
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

