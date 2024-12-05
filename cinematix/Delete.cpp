#include <stdio.h>
#include <conio.h>
#include "bioskop.h"

Delete(){
	char a,jawab;		
	FILE *Tickets=fopen("Report.txt", "r");
 	
	
	if(!Tickets)
	{ //cek apakah filenya ada atau tidak
		printf("Data masih kosong !\n");
		getch();
	}
	else 
	{
		
		printf("Apakah anda yakin? (y/t) : ");
		fflush(stdin);
		a=getchar();
		if(a=='y' || a=='Y')
		{
			fclose(Tickets);
			remove("Report.txt");
			printf("Data berhasil dihapus! \n");
		}
		else if(a=='t' || a=='T')
		{
			printf("Data tidak jadi dihapus! \n");
		}
		else
		{
			return Delete();
			printf("Invalid input... Silahkan Ulangi");
		}
	}
	getch();
	
	printf("kembali ke menu utama ? ");
	scanf("%s", &jawab);
		if(jawab == 'y'|jawab == 'Y'){
			menu();
		}else{
			return 0;
		}
		
	
}
