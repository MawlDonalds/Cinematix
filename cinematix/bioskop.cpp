// bioskop.cpp
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <ctype.h>   
#include "bioskop.h"

// Implementasi fungsi convertSeat
int convertSeat(char row, int number){
    // Validasi input
    if(row < 'A' || row > 'J' || number < 1 || number > 5){
        return -1; // Invalid seat
    }
    return (row - 'A') * 5 + number;
}

// Fungsi untuk membaca daftar film dari file
int readFilms(Show films[], int maxFilms){
    FILE *file = fopen("films.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file films.txt\n");
        getch();
        return 0;
    }
    int count = 0;
    while(fscanf(file, "%d %s", &films[count].filmID, films[count].judul) != EOF && count < maxFilms){
        count++;
    }
    fclose(file);
    return count;
}

// Fungsi untuk membaca jam tayang dari file
int readShowtimes(int filmID, float jamx[], float jamy[], int maxShowtimes){
    FILE *file = fopen("showtimes.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file showtimes.txt\n");
        getch();
        return 0;
    }
    int id, jamNumber;
    float jam;
    while(fscanf(file, "%d %d %f", &id, &jamNumber, &jam) != EOF){
        if(id == filmID && jamNumber >=1 && jamNumber <=6){
            // Asumsikan filmID 1 dan 4 menggunakan jamx (weekday), 2 dan 3 menggunakan jamy (weekend)
            if(id == 1 || id == 4){
                jamx[jamNumber] = jam;
            }
            else{
                jamy[jamNumber] = jam;
            }
        }
    }
    fclose(file);
    return 1;
}

// Fungsi untuk membaca harga tiket
int readPrices(float &weekdayPrice, float &weekendPrice){
    FILE *file = fopen("prices.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file prices.txt\n");
        getch();
        return 0;
    }
    fscanf(file, "%f %f", &weekdayPrice, &weekendPrice);
    fclose(file);
    return 1;
}

// Fungsi untuk membaca status kursi
int readSeats(char seats[]){
    FILE *file = fopen("seats.txt", "r");
    if(file == NULL){
        printf("Gagal membuka file seats.txt\n");
        getch();
        return 0;
    }
    int seatNum;
    char status;
    while(fscanf(file, "%d %c", &seatNum, &status) != EOF){
        if(seatNum >=1 && seatNum <=50){
            seats[seatNum] = status;
        }
    }
    fclose(file);
    return 1;
}

// Fungsi untuk memperbarui status kursi
int updateSeats(char seats[]){
    FILE *file = fopen("seats.txt", "w");
    if(file == NULL){
        printf("Gagal membuka file seats.txt untuk menulis\n");
        getch();
        return 0;
    }
    for(int i=1; i<=50; i++){
        fprintf(file, "%d %c\n", i, seats[i]);
    }
    fclose(file);
    return 1;
}

// Implementasi fungsi displaySeats
void displaySeats(char seats[]){
    printf("================ SCREEN =================\n");
    
    for(char row = 'A'; row <= 'J'; row++){
        printf("Baris %c: ", row);
        for(int num = 1; num <=5; num++){
            int seatNumber = convertSeat(row, num);
            if(seatNumber != -1){
                printf(" %c%d[%c] ", row, num, seats[seatNumber]);
            }
        }
        printf("\n");
    }
    printf("==========================================\n\n");
    printf("Status: [B] Belum Terisi | [T] Terisi\n\n");
}

// Fungsi utama untuk proses pembelian tiket
int getBioskop(){
    FILE *Tickets;
    Nonton dt;
    Show films[5]; // Asumsikan maksimal 4 film
    float weekdayPrice, weekendPrice;
    char seats[51]; // 1-50

    // Membaca data dari file
    int filmCount = readFilms(films, 5);
    if(filmCount == 0){
        return 0;
    }

    // Membaca jam tayang untuk setiap film
    for(int i = 0; i < filmCount; i++){
        memset(films[i].jamx, 0, sizeof(films[i].jamx));
        memset(films[i].jamy, 0, sizeof(films[i].jamy));
        readShowtimes(films[i].filmID, films[i].jamx, films[i].jamy, 6);
    }

    // Membaca harga tiket
    if(!readPrices(weekdayPrice, weekendPrice)){
        return 0;
    }
    dt.hargatiket_weekday = weekdayPrice;
    dt.hargatiket_weekend = weekendPrice;

    // Membaca status kursi
    memset(seats, 'B', sizeof(seats)); // Default Belum Terisi
    if(!readSeats(seats)){
        return 0;
    }

    // Mendapatkan tanggal saat ini
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int day = local->tm_mday;            // hari
    int month = local->tm_mon + 1;       // bulan
    int year = local->tm_year + 1900;    // tahun

    // Menentukan apakah hari ini weekend atau weekday
    int wday = local->tm_wday; // 0 = Sunday, 6 = Saturday
    float harga_tiket;
    if(wday == 0 || wday == 6){
        harga_tiket = dt.hargatiket_weekend;
    }
    else{
        harga_tiket = dt.hargatiket_weekday;
    }

    while(1){
        kembali:
        system("cls");
        printf("=========================================================================\n");
        printf("\t\t\t Cinemaxxx \n");
        printf("=========================================================================\n\n");
        printf("\t\t\t DAFTAR FILM\n");
        printf("-------------------------------------------------------------------------\n");
        printf(" | Studio |    Film\t|------------------------------------------------\n");
        printf(" |        | \t\t|   1   |   2   |   3   |   4   |   5   |   6   |\n");
        printf(" |------------------------------|--------------------------------------\n");
        for(int i = 0; i < filmCount; i++){
            printf(" |   %d    | %s\t| ", films[i].filmID, films[i].judul);
            for(int j =1; j<=6; j++){
                if(films[i].filmID ==1 || films[i].filmID ==4){
                    printf("%.2f | ", films[i].jamx[j]);
                }
                else{
                    printf("%.2f | ", films[i].jamy[j]);
                }
            }
            printf("\n");
        }
        printf(" |----------------------|------------------------------------------------\n\n");
        printf("=========================================================================\n");
        printf("Harga Tiket : Rp. %.2f\n", harga_tiket);		
        printf("Today is %s", ctime(&now));

        // Pilihan film
        filminput:
        fflush(stdin);
        printf("Pilih Film(1-%d) : ", filmCount);
        int selectedFilm;
        int status = scanf("%d", &selectedFilm);
        int temp;
        while(status != 1){
            while((temp = getchar()) != EOF && temp != '\n');
            printf("Invalid input.. Masukkan angka: ");
            status = scanf("%d", &selectedFilm);
        }
        if(selectedFilm < 1 || selectedFilm > filmCount){
            printf("Invalid..! Hanya tersedia %d list film \n", filmCount);
            getch();
            goto filminput;
        }

        // Pilihan jam tayang
        jaminput:
        fflush(stdin);
        printf("Pilih Jam ke(1-6) : ");
        int jamNumber;
        status = scanf("%d", &jamNumber);
        while(status != 1){
            while((temp = getchar()) != EOF && temp != '\n');
            printf("Invalid input.. Masukkan angka: ");
            status = scanf("%d", &jamNumber);
        }
        if(jamNumber < 1 || jamNumber >6){
            printf("Masukkan pilihan yang valid\n");
            getch();
            goto jaminput;
        }

        // Tampilkan film dan jam tayang yang dipilih
        printf("Film: %s\n", films[selectedFilm-1].judul);			
        if(films[selectedFilm-1].filmID == 1 || films[selectedFilm-1].filmID ==4){
            printf("Jam: %.2f\n", films[selectedFilm-1].jamx[jamNumber]);
        }
        else{
            printf("Jam: %.2f\n", films[selectedFilm-1].jamy[jamNumber]);
        }

        // Pilihan jumlah tiket
        jumlahTiket:
        fflush(stdin);
        printf("Jumlah tiket yang akan dibeli : ");
        int jumlahTiket;
        status = scanf("%d", &jumlahTiket);
        while(status != 1){
            while((temp = getchar()) != EOF && temp != '\n');
            printf("Invalid input.. Masukkan angka: ");
            status = scanf("%d", &jumlahTiket);
        }
        if(jumlahTiket <= 0){
            printf("Jumlah tiket harus lebih dari 0!\n");
            getch();
            goto kembali;
        }

        // Setelah user memilih film, jam tayang, dan jumlah tiket, 
        // Barulah kita tampilkan layout kursi
        system("cls");
        printf("=========================================================================\n");
        printf("\t\t\t Cinemaxxx \n");
        printf("=========================================================================\n\n");
        printf("Film: %s\n", films[selectedFilm-1].judul);			
        if(films[selectedFilm-1].filmID == 1 || films[selectedFilm-1].filmID ==4){
            printf("Jam: %.2f\n", films[selectedFilm-1].jamx[jamNumber]);
        }
        else{
            printf("Jam: %.2f\n", films[selectedFilm-1].jamy[jamNumber]);
        }
        printf("Jumlah tiket: %d\n", jumlahTiket);
        printf("Harga Tiket : Rp. %.2f\n", harga_tiket);

        printf("\n\n======== Pilih Tempat Duduk ========\n");
        displaySeats(seats); 
        printf("====================================\n\n");

        // Pilihan tempat duduk
        char hurufkursi[50];
        int angkakursi[50];
        for(int h = 0; h < jumlahTiket; h++){
            kursi:
            fflush(stdin);
            printf("Pilih seat(A-J) untuk tiket ke-%d: ", h+1);
            scanf(" %c", &hurufkursi[h]);
            hurufkursi[h] = toupper(hurufkursi[h]); // Pastikan huruf kapital
            printf("Pilih Nomor Kursi(1-5) untuk tiket ke-%d: ", h+1);
            status = scanf("%d", &angkakursi[h]);
            while(status != 1){
                while((temp = getchar()) != EOF && temp != '\n');
                printf("Invalid input.. Masukkan angka: ");
                status = scanf("%d", &angkakursi[h]);
            }
            if(angkakursi[h] < 1 || angkakursi[h] > 5){
                printf("Pilihan tidak valid, silahkan Ulangi ! \n\n");
                getch();
                goto kursi;
            }

            // Konversi huruf dan angka ke nomor kursi
            int seatNumber = convertSeat(hurufkursi[h], angkakursi[h]);
            if(seatNumber == -1){
                printf("Pilihan kursi tidak valid!\n");
                getch();
                goto kursi;
            }

            // Cek apakah kursi tersedia
            if(seats[seatNumber] == 'T' || seats[seatNumber] == 't'){
                printf("Kursi %c%d sudah terisi. Silakan pilih kursi lain.\n", hurufkursi[h], angkakursi[h]);
                getch();
                goto kursi;
            }
        }

        // Tampilan Checkout			
        printf("Jumlah Pesanan : %d\n", jumlahTiket);
        printf("-----------------------------------------\n");
        printf("| No |\tFilm\t| Kursi | Harga |\n");
        printf("-----------------------------------------\n");
        for(int i = 0; i < jumlahTiket; i++){
            printf("| %2d | %s\t|  %c%d  | %.2f |\n", i+1, films[selectedFilm-1].judul, hurufkursi[i], angkakursi[i], harga_tiket);
        }
        printf("-----------------------------------------\n");
        dt.totalharga = harga_tiket * jumlahTiket;

        // Transaksi pembayaran		
        pembayaran:
        fflush(stdin);
        printf("Total harga\t\tRp %.2f\n", dt.totalharga);
        printf("Bayar\t\t\tRp. ");
        float bayar;
        status = scanf("%f", &bayar);
        while(status != 1){
            while((temp = getchar()) != EOF && temp != '\n');
            printf("Invalid input.. Masukkan biaya: ");
            status = scanf("%f", &bayar);
        }

        if(bayar < dt.totalharga){
            printf("Uang tidak cukup, ulangi pembayaran atau batalkan transaksi? (U/B)\n\n");
            char choice;
            scanf(" %c", &choice);
            choice = toupper(choice);
            if(choice == 'U'){
                goto pembayaran;		
            }
            else{
                printf("Transaksi dibatalkan.\n");
                getch();
                goto kembali;
            }											
        }
        else{
            dt.kembalian2 = bayar - dt.totalharga;
        }

        printf("\t\t\t____\n\n");
        printf("Kembalian\t\tRp %.2f\n", dt.kembalian2);

        printf("Cetak tiket (Y/N) ? ");
        char cetak;
        scanf(" %c", &cetak);
        cetak = toupper(cetak);
        system("cls");
        if(cetak == 'Y'){
            Tickets = fopen("Report.txt", "a+");
            if(Tickets == NULL){
                printf("Gagal membuka file Report.txt\n");
                getch();
                return 0;
            }

            // Membaca status kursi untuk diperbarui
            // Membaca semua kursi ke dalam array
            char updatedSeats[51];
            memset(updatedSeats, 'B', sizeof(updatedSeats)); // Default Belum Terisi
            FILE *seatFile = fopen("seats.txt", "r");
            if(seatFile == NULL){
                printf("Gagal membuka file seats.txt\n");
                getch();
                fclose(Tickets);
                return 0;
            }
            int seatNum;
            char seatStatus;
            while(fscanf(seatFile, "%d %c", &seatNum, &seatStatus) != EOF){
                if(seatNum >=1 && seatNum <=50){
                    updatedSeats[seatNum] = seatStatus;
                }
            }
            fclose(seatFile);

            // Mengubah status kursi yang dibeli menjadi 'T'
            for(int i = 0; i < jumlahTiket; i++){
                int seatNumber = convertSeat(hurufkursi[i], angkakursi[i]);
                if(seatNumber != -1){
                    updatedSeats[seatNumber] = 'T';
                }
            }

            // Menulis kembali status kursi ke file
            seatFile = fopen("seats.txt", "w");
            if(seatFile == NULL){
                printf("Gagal membuka file seats.txt untuk menulis\n");
                getch();
                fclose(Tickets);
                return 0;
            }
            for(int i=1; i<=50; i++){
                fprintf(seatFile, "%d %c\n", i, updatedSeats[i]);
            }
            fclose(seatFile);

            // Menulis tiket ke Report.txt
            for(int i = 0; i < jumlahTiket; i++){
                printf("------------------------------------\n");
                printf("|\tCinemaxxx\t\t|\n");
                printf("------------------------------------\n");
                printf("| %s\t\t\t|\n", films[selectedFilm-1].judul);
                printf("|Tanggal  : %02d-%02d-%04d \t|\n", day, month, year);
                if(films[selectedFilm-1].filmID ==1 || films[selectedFilm-1].filmID ==4){
                    printf("|Time : %.2f\t\t\t|\n", films[selectedFilm-1].jamx[jamNumber]);
                }
                else{
                    printf("|Time : %.2f\t\t\t|\n", films[selectedFilm-1].jamy[jamNumber]);
                }		
                printf("|Row  : %c Seat : %d \t\t|\n", hurufkursi[i], angkakursi[i]);
                printf("------------------------------------\n\n");

                fprintf(Tickets, "Film: %s Tanggal: %02d-%02d-%04d Jam: %.2f Kursi: %c%d Harga: %.2f\n",
                        films[selectedFilm-1].judul, day, month, year,
                        (films[selectedFilm-1].filmID ==1 || films[selectedFilm-1].filmID ==4) ? films[selectedFilm-1].jamx[jamNumber] : films[selectedFilm-1].jamy[jamNumber],
                        hurufkursi[i], angkakursi[i], harga_tiket);
            }
            fclose(Tickets);

            buyagain:
            printf("Ingin membeli tiket lagi (Y/N) ?");
            char jawab;
            scanf(" %c", &jawab);
            jawab = toupper(jawab);
            if(jawab == 'Y'){
                goto kembali;
            }
            else if(jawab == 'N'){
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
        menuChoice = toupper(menuChoice);
        if(menuChoice == 'Y'){
            system("cls");
            return 0; // Kembali ke menu user
        }
        else{
            exit(1);
        }
    }
}

