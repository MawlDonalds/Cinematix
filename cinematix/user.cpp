// user.cpp
#include "bioskop.h"

// Deklarasi fungsi
int userMenu();

int userMenu(){
    int pilihan;
    while (1) {
        system("cls");
        printf("=========================================================================\n");
        printf("\t\t\t Menu USER FunCinema \n");
        printf("=========================================================================\n\n");
        printf("\t1. Beli Tiket\n");
        printf("\t2. Logout\n");
        printf("=========================================================================\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch (pilihan) {
            case 1:
                getBioskop(); // Memanggil fungsi beli tiket
                break;
            case 2:
                Logout(); // Memanggil fungsi logout
                return 0; // Kembali ke main menu tanpa menutup program
            default:
                printf("Pilihan tidak valid!\n");
                getch();
        }
    }
    return 0;
}

