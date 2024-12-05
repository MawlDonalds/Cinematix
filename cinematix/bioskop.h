// bioskop.h
#ifndef BIOSKOP_H
#define BIOSKOP_H

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

// Struktur untuk data tiket nonton
struct Nonton {	
    int tiket;	
    float kembalian2, bayar, totalharga;
    float hargatiket_weekday, hargatiket_weekend;
    char cetak, pesan, nonton, menu, kursi;
};

// Struktur untuk data show film
struct Show {		
    char jud[5][50]; // Inisialisasi di bioskop.cpp
    int film;
    int day, month, year;
    float jamx[7]; // Inisialisasi di bioskop.cpp
    int jam; 
    char hurufkursi[20][2]; // Perubahan dari [20][50] menjadi [20][2] untuk karakter tunggal
    int angkakursi[50];
    float jamy[7]; // Inisialisasi di bioskop.cpp
};

// Struktur untuk ADMIN dan USER
struct Account {
    char username[20];
    char password[20];
    char role[10];
};

// Deklarasi fungsi
int getBioskop();
int Delete();
int Tampil_Lihat();
int getLogin();
int getLoading();
int menu();
int Logout();
int registerUser();
int adminMenu();
int userMenu();

#endif 

