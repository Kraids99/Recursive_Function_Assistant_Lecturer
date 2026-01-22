#include "header.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	str judul, genre;
	int menu, submenu, tahun, number;
	Data data;
	List L, R;
	char YesOrNo;
	address node;
	createEmpty(&L);
	createEmpty(&R);
	
	do
	{
		system("cls");
		printf("\n\t===[ Playlist Prima Music ]===");
		printf("\n[1] Tambah Lagu");
		printf("\n[2] Tampil Lagu");
		printf("\n[3] Hapus Lagu");
		printf("\n\n\t==[ BONUS ]==");
		printf("\n[4] Reverse List Lagu");
		printf("\n\n\t==[ TUGAS ]==");
		printf("\n[5] Putar Lagu");
		printf("\n[6] Riwayat Lagu\n");
		printf("\n[0] Keluar");
		printf("\n>> ");scanf("%d", &menu);
		switch(menu)
		{
			case 1:
				printf("\n\t===[ Tambah Lagu ]===\n");
				
				printf("\n\tJudul Lagu\t: ");fflush(stdin);gets(data.judul);
					
				while(1)
				{
					printf("\n\tGenre Lagu (Pop/Jazz/Rock): ");fflush(stdin);gets(data.genre);
					if(strcmpi(data.genre,"Pop")!=0 && strcmpi(data.genre,"Jazz")!=0 && strcmpi(data.genre,"Rock")!=0)
						printf("\n\t[!] Genre Lagu invalid\n");
					else break;
				}
				printf("\n\tDurasi Lagu\t: ");scanf("%d", &data.durasi);
				insertLast(&L, alokasi(data));
				printf("\n\t[+] Berhasil Menambahkan Lagu");
			break;
			
			case 2:
				if(isEmpty(L))
				{
					printf("\n\t[!] Playlist masih kosong");
					break;
				}
				printf("\n\t===[ Daftar Lagu ]===\n");
				printAll(L, 1);
			break;
			
			case 3:
				if(isEmpty(L))
				{
					printf("\n\t[!] Playlist masih kosong");
					break;
				}
				printf("\n===[ Hapus Lagu ]===\n");
				number = randomNumber(1,3);
				if(number == 1)
					strcpy(genre,"Pop");
				if(number == 2)
					strcpy(genre,"Jazz");
				if(number == 3)
					strcpy(genre,"Rock");
				if(!cekGenre(L, genre))
				{
					printf("\n\t[!] Genre %s belum ada Lagu", genre);
					break;
				}
				printf("\n\n===[ Daftar Lagu dengan Genre %s ]===\n", genre);
				number = countJudul(L, genre, 0);
				printf("\n Jumlah Lagu : %d", number);
				printGenre(L, 1, genre);
				printf("\nApakah Anda yakin ingin menghapus lagu %s (y/n) ? ", judul);YesOrNo = getche();
				if(YesOrNo == 'y')
				{
					deleteByGenre(&L, genre);
					printf("\n\n\t[*] Berhasil menghapus data lagu");
				}else printf("\n\n\t[!] Tidak jadi menghapus data lagu");
			break;
			
			//Bonus
			case 4:
				if(isEmpty(L))
				{
					printf("\n\t[!] Playlist masih kosong");
					break;
				}
				reverseList(&L);
				printf("\n\t[+] Berhasil ngereverse Playlist\n");
			break;
			
			//Tugas
			case 5:
				if(isEmpty(L))
				{
					printf("\n\t[!] Playlist masih kosong");
					break;
				}
				number = countNodes(L);
				number = randomNumber(1,number);
				node = randomNode(L, number);
				printf("\n\t===[ Putar Lagu ]===\n");
				printSingle(node);
				insertFirst(&R, alokasi(node->data));
				printf("\n\t[+] Lagu %s berhasil diputar", node->data.judul);
				deleteAt(&L, node);		
			break;	
			
			case 6:
				if(isEmpty(R))
				{
					printf("\n\t[!] Riwayat Pemutaran masih kosong\n");
					break;
				}
				printf("\n\t===[ Daftar Riwayat Lagu ]===\n");
				printAll(R, 1);
			break;
			
			case 0:
				printf("\n[Nama - NPM - KELAS]");
			break;
			
			default:
				printf("\nMenu Invalid");
			break;
		}getch();
	}while(menu != 0);
	return 0;
}
