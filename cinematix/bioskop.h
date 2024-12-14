// bioskop.h
#ifndef BIOSKOP_H
#define BIOSKOP_H

// Struktur untuk informasi film dan jam tayang
struct Show {		
    int filmID;
    char judul[50];
    float jamx[7]; // Indeks 1-6 untuk jam ke-1 hingga ke-6 (weekday)
    float jamy[7]; // Indeks 1-6 untuk jam ke-1 hingga ke-6 (weekend)
};

// Struktur untuk informasi studio
struct Studio {
    int studioID;
    char namaStudio[50];
};

// Struktur untuk transaksi pemesanan
struct Nonton {
    float hargatiket_weekday;
    float hargatiket_weekend;
    float totalharga;
    float kembalian2;
    // Tambahkan anggota lainnya jika diperlukan
};

// Deklarasi fungsi utama
int getBioskop();
int userMenu();
int adminMenu();
int Logout();

// Deklarasi fungsi fitur Admin
int editFilm();
int editJamTayang();
int editStudio();
int editHarga();
int lihatRiwayat();
int editTempatDuduk();

// Deklarasi fungsi fitur User
int beliTiket();
int lihatFilm();
int lihatRiwayatUser();

// Deklarasi fungsi login dan register
int login();
int registerUser();

// Deklarasi fungsi getLogin
int getLogin();
int Tampil_Lihat();
int Delete();

// Deklarasi fungsi convertSeat
int convertSeat(char row, int number);

// Deklarasi fungsi displaySeats
void displaySeats(char seats[]);

#endif // BIOSKOP_H

