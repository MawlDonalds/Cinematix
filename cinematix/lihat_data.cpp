// lihat_data.cpp
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include "bioskop.h"

int Tampil_Lihat(){		
    Nonton dt;
    Show sh;
    char buffer[256];
    char jawab;
    
    FILE *Tickets = fopen("Report.txt", "r");
    if (!Tickets){
        printf ("File tidak dapat dibuka atau masih kosong.\n");
        printf("Kembali ke menu utama? (Y/N): ");
        scanf(" %c", &jawab);
        if(jawab == 'y' || jawab == 'Y'){
            menu();
        }
        else{
            return 0;
        }
    }
    else{
        system("cls");
        printf("-------------------------\n");
        printf("|\tBioskop Keren\t\t|\n");
        printf("-------------------------\n");
        printf("| Film | Tanggal | Jam | Row | Seat | \n\n");
        while (fgets(buffer, sizeof(buffer), Tickets)){
            printf("%s", buffer);
        }
        fclose(Tickets);
        printf("\nKembali ke menu? (Y/N): ");
        scanf(" %c", &jawab);
        if(jawab == 'y' || jawab == 'Y'){
            menu();
        }
        else{
            exit(1);
        }
    }
    return 0;
}

