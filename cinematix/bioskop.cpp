// bioskop.cpp
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include "bioskop.h"

// Deklarasi fungsi
int getBioskop();
int Delete();
int Tampil_Lihat();
int getLoading();
int menu(); // Pastikan fungsi menu didefinisikan atau dipanggil sesuai struktur baru

int getBioskop(){
    FILE *Tickets;
    Nonton dt;
    Show sh;
    
    time_t now;
    time(&now);

    struct tm *local = localtime(&now);

    sh.day = local->tm_mday;            // get day of month (1 to 31)
    sh.month = local->tm_mon + 1;      // get month of year (0 to 11)
    sh.year = local->tm_year + 1900;   // get year since 1900

    for (;;){
        kembali:
        system("cls");
        printf("=========================================================================\n");
        printf("\t\t\t FunCinema \n");
        printf("=========================================================================\n\n");
        printf("\t\t\t DAFTAR FILM\n");
        printf("-------------------------------------------------------------------------\n");
        printf(" |\t  |\t\t|\t\t\tJam\t\t\t|\n");
        printf(" | Studio |    Film\t|------------------------------------------------\n");
        printf(" |\t  | \t\t|   1   |   2   |   3   |   4   |   5   |   6   |\n");
        printf(" |----------------------|------------------------------------------------\n");
        printf(" |   1   | Sepiderman\t| 11.30 | 12.55 | 14.20 | 16.10 | 19.10 | 20.45 |\n");
        printf(" |   2   | BOLANG\t| 11.45 | 13.00 | 15.30 | 17.20 | 19.15 | 21.00 |\n");
        printf(" |   3   | Frozen 2\t| 11.45 | 13.00 | 15.30 | 17.20 | 19.15 | 21.00 |\n");
        printf(" |   4   | My War\t| 11.30 | 12.55 | 14.20 | 16.10 | 19.10 | 20.45 |\n");
        printf(" |----------------------|------------------------------------------------\n\n");
        printf("=========================================================================\n");
        printf("Harga Tiket : Rp. %.3f\n", dt.hargatiket_weekday);		
        printf("Today is %s", ctime(&now));
        
        // Pilihan film
        filminput:
        fflush(stdin);
        printf("Pilih Film(1-4) : ");
        // VALIDASI HANYA ANGKA
        int status, temp;
        status = scanf("%d", &sh.film);
        while(status != 1){
            while((temp = getchar()) != EOF && temp != '\n');
            printf("Invalid input.. Masukkan angka: ");
            status = scanf("%d", &sh.film);
        }
        if(sh.film < 1 || sh.film > 4){
            printf("Invalid..! Hanya tersedia 4 list film \n");
            getch();
            goto filminput;
        }
        
        // Pilihan jam tayang
        jaminput:
        fflush(stdin);
        printf("Pilih Jam ke(1-6) : ");
        // VALIDASI HANYA ANGKA
        int status1, temp1;
        status1 = scanf("%d", &sh.jam);
        while(status1 != 1){
            while((temp1 = getchar()) != EOF && temp1 != '\n');
            printf("Invalid input.. Masukkan angka: ");
            status1 = scanf("%d", &sh.jam);
        }
        if(sh.jam < 1 || sh.jam > 6){
            printf("Masukkan pilihan yang valid\n");
            getch();
            goto jaminput;
        }
        
        // Tampilkan film dan jam tayang yang dipilih
        printf("Film: %s\n", sh.jud[sh.film]);			
        if(sh.film == 1 || sh.film == 4){
            printf("Jam: %.2f\n", sh.jamx[sh.jam]);
        }
        else if(sh.film == 2 || sh.film == 3){
            printf("Jam: %.2f\n", sh.jamy[sh.jam]);
        }
        
        // Pilihan jumlah tiket
        fflush(stdin);
        printf("Jumlah tiket yang akan dibeli : ");
        // VALIDASI HANYA ANGKA
        int status2, temp2;
        status2 = scanf("%d", &dt.tiket);
        while(status2 != 1){
            while((temp2 = getchar()) != EOF && temp2 != '\n');
            printf("Invalid input.. Masukkan angka: ");
            status2 = scanf("%d", &dt.tiket);
        }
        if(dt.tiket <= 0){
            printf("Jumlah tiket harus lebih dari 0!\n");
            getch();
            goto kembali;
        }
        
        // Pilihan tempat duduk
        kursi:
        int h;
        for(h = 0; h < dt.tiket; h++){
            fflush(stdin);
            printf("Pilih seat(A-J) : ");
            scanf(" %c", &sh.hurufkursi[h][0]);				
            printf("Pilih Nomor Kursi(1-50) : ");
            // VALIDASI HANYA ANGKA
            int status3, temp3;
            status3 = scanf("%d", &sh.angkakursi[h]);
            while(status3 != 1){
                while((temp3 = getchar()) != EOF && temp3 != '\n');
                printf("Invalid input.. Masukkan angka: ");
                status3 = scanf("%d", &sh.angkakursi[h]);
            }
            if(sh.angkakursi[h] < 1 || sh.angkakursi[h] > 50){
                printf("Pilihan tidak valid, silahkan Ulangi ! \n\n");
                getch();
                goto kursi;
            }
        }
        
        // Tampilan Checkout			
        inptiket:	
        int i;
        fflush(stdin);
        printf("Jumlah Pesanan : %d\n", dt.tiket);
        printf("-----------------------------------------\n");
        printf("| No |\tFilm\t| Kursi | Harga |\n");
        printf("-----------------------------------------\n");
        for(i = 0; i < dt.tiket; i++){
            printf("| %2d | %s\t|  %c%d  | %.3f |\n", i+1, sh.jud[sh.film], sh.hurufkursi[i][0], sh.angkakursi[i], dt.hargatiket_weekday);
        }
        printf("-----------------------------------------\n");
        dt.totalharga = dt.hargatiket_weekday * dt.tiket;
        
        // Transaksi pembayaran		
        balik:
        fflush(stdin);
        printf("Total harga\t\tRp %.3f\n", dt.totalharga);
        printf("Bayar\t\t\tRp. ");
        // VALIDASI HANYA ANGKA
        int status4, temp4;
        status4 = scanf("%f", &dt.bayar);
        while(status4 != 1){
            while((temp4 = getchar()) != EOF && temp4 != '\n');
            printf("Invalid input.. Masukkan biaya: ");
            status4 = scanf("%f", &dt.bayar);
        }
        
        if(dt.bayar < dt.totalharga){
            printf("Uang tidak cukup, ulangi pembayaran atau batalkan transaksi? (U/B)\n\n");
            char choice;
            scanf(" %c", &choice);
            if(choice == 'U' || choice == 'u'){
                goto balik;		
            }
            else{
                printf("Transaksi dibatalkan.\n");
                getch();
                goto kembali;
            }											
        }
        else{
            dt.kembalian2 = dt.bayar - dt.totalharga;
        }
        
        printf("\t\t\t____\n\n");
        printf("Kembalian\t\tRp %.3f\n", dt.kembalian2);
        
        printf("Cetak tiket (Y/N) ? ");
        char cetak;
        scanf(" %c", &cetak);
        system("cls");
        if(cetak == 'y' || cetak == 'Y'){
            Tickets = fopen("Report.txt", "a+");
            for(i = 0; i < dt.tiket; i++){
                printf("------------------------------------\n");
                printf("|\tFunCinema\t\t|\n");
                printf("------------------------------------\n");
                printf("| %s\t\t\t|\n", sh.jud[sh.film]);
                printf("|Tanggal : %d-%d-%d \t\t|\n", sh.day, sh.month, sh.year);
                if(sh.film == 1 || sh.film == 4){
                    printf("|Time : %.2f\t\t\t|\n", sh.jamx[sh.jam]);
                }
                else if(sh.film == 2 || sh.film == 3){
                    printf("|Time : %.2f\t\t\t|\n", sh.jamy[sh.jam]);
                }		
                printf("|Row  : %c Seat : %d \t\t|\n", sh.hurufkursi[i][0], sh.angkakursi[i]);
                printf("------------------------------------\n\n");

                fprintf(Tickets, "%s %02d/%02d/%04d %.2f %c %d\n", sh.jud[sh.film], sh.day, sh.month, sh.year, 
                        (sh.film == 1 || sh.film == 4) ? sh.jamx[sh.jam] : sh.jamy[sh.jam], 
                        sh.hurufkursi[i][0], sh.angkakursi[i]);
            }
            fclose(Tickets);
            
            buyagain:
            printf("Ingin membeli tiket lagi (Y/N) ?");
            char jawab;
            scanf(" %c", &jawab);
            if(jawab == 'y' || jawab == 'Y'){
                goto kembali;
            }
            else if(jawab == 'n' || jawab == 'N'){
                goto selesai;
            }
            else{
                printf("Masukkan Pilihan yang valid");
                getch();
                goto buyagain;
            }
        }
        else{
            // Tiket tidak dicetak
            exit(1);
        }

        selesai:
        system("cls");
        printf("Terimakasih telah membeli tiket bioskop kami\n Selamat Menonton :)\n\n ");
        printf("Kembali Ke Menu Utama ? (Y/N)");
        char menuChoice;
        scanf(" %c", &menuChoice);
        if(menuChoice == 'y' || menuChoice == 'Y'){
            system("cls");
            // Panggil menu USER
            // Implementasikan sesuai struktur baru
            // Misalnya, kembali ke userMenu()
            // userMenu();
            return getBioskop(); // Atau panggil fungsi yang sesuai
        }
        else{
            exit(1);
        }
    }
}

