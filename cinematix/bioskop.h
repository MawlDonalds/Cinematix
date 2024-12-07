// bioskop.h
#ifndef BIOSKOP_H
#define BIOSKOP_H

struct Show {		
    int filmID;
    char judul[50];
    float jamx[7]; // Indeks 1-6 untuk jam ke-1 hingga ke-6 (weekday)
    float jamy[7]; // Indeks 1-6 untuk jam ke-1 hingga ke-6 (weekend)
};

struct Studio {
    int studioID;
    char namaStudio[50];
};

struct Nonton {
    float hargatiket_weekday;
    float hargatiket_weekend;
    float totalharga;
    float kembalian2;
    // Tambahkan anggota lainnya jika diperlukan
};

// Deklarasi fungsi
int getBioskop();
int userMenu();
int adminMenu();
int Logout();

// Fitur Admin
int editFilm();
int editJamTayang();
int editStudio();
int editHarga();
int lihatRiwayat();
int editTempatDuduk();

// Fitur User
// Tambahkan deklarasi fungsi lainnya jika diperlukan

#endif

