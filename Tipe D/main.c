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
		printf("\n\t===[ Perpustakaan ]===");
		printf("\n[1] Tambah Buku");
		printf("\n[2] Tampil Buku");
		printf("\n[3] Peminjaman Buku");
		printf("\n\n\t==[ BONUS ]==");
		printf("\n[4] Memisahkan Buku Berdasarkan Tahun");
		printf("\n\n\t==[ TUGAS ]==");
		printf("\n[5] Riwayat Pinjam");
		printf("\n[6] Pengembalian Buku\n");
		printf("\n[0] Keluar");
		printf("\n>> ");scanf("%d", &menu);
		switch(menu)
		{
			case 1:
				printf("\n\t===[ Tambah Buku ]===\n");
				printf("\n\tJudul Buku\t: ");fflush(stdin);gets(data.judul);
				while(1)
				{
					printf("\n\tGenre Buku (Komedi/Romance/Horror): ");fflush(stdin);gets(data.genre);
					if(strcmpi(data.genre,"Komedi")!=0 && strcmpi(data.genre,"Romance")!=0 && strcmpi(data.genre,"Horror")!=0)
						printf("\n\t[!] Genre Buku invalid\n");
					else break;
				}
				printf("\n\tTahun Terbit\t: ");scanf("%d", &data.tahunTerbit);
				insertFirst(&L, alokasi(data));
				printf("\n\t[+] Berhasil Menambahkan Buku");
			break;
			
			case 2:
				if(isEmpty(L))
				{
					printf("\n\t[!] Data perpustakaan masih kosong");
					break;
				}
				printf("\n\t===[ Daftar Buku ]===\n");
				printAll(L, 1);
			break;
			
			case 3:
				if(isEmpty(L))
				{
					printf("\n\t[!] Data perpustakaan masih kosong");
					break;
				}
				system("cls");
				printf("\n===[ Peminjaman Buku ]===\n");
				printf("\nPilih Genre Buku yang ingin di pinjam (Komedi/Romance/Horror): ");fflush(stdin);gets(genre);
				if(strcmpi(genre,"Komedi")!=0 && strcmpi(genre,"Romance")!=0 && strcmpi(genre,"Horror")!=0)
				{
					printf("\n\t[!] Genre Buku invalid\n");
					break;
				}
				if(!cekGenre(L, genre))
				{
					printf("\n\t[!] Genre ini belum ada Buku");
					break;
				}
				printf("\n\n===[ Daftar Buku dengan Genre %s ]===\n", genre);
				printGenre(L, 1, genre);
				printf("\n\nPilih Judul Buku yang ingin di pinjam : ");fflush(stdin);gets(judul);
				if(cekJudul(L, judul, genre)==1)
				{
					node = findNode(L, judul, genre);
					printSingle(node);
					printf("\nApakah Anda yakin ingin meminjam buku %s (y/n) ? ", judul);YesOrNo = getche();
					if(YesOrNo == 'y')
					{
						insertFirst(&R, alokasi(node->data));
						deleteAt(&L, node);
						printf("\n\n\t[*] Berhasil meminjam buku");
					}else printf("\n\n\t[!] Tidak jadi meminjam buku");
				}else printf("\n\n\t[!] Buku dengan judul %s tidak ditemukan", judul);
			break;
			
			//Bonus
			case 4:
				if(isEmpty(L))
				{
					printf("\n\t[!] Data perpustakaan masih kosong");
					break;
				}
				printf("\n\t===[ Buku sebelum tahun 2000 ]===\n");
				printTahunbawah(L, 1);
				printf("\n\t===[ Buku setelah tahun 2000 ]===\n");
				printTahunatas(L, 1);
			break;
			
			//Tugas
			case 5:
				if(isEmpty(R))
				{
					printf("\n\t[!] Riwayat Peminjaman masih kosong\n");
					break;
				}
				printf("\n\t===[ Daftar Buku Yang Dipinjam ]===\n");
				printAll(R, 1);
			break;
			
			case 6:
				if(isEmpty(R))
				{
					printf("\n\t[!] Riwayat Peminjaman masih kosong");
					break;
				}
				number = randomNumber(1,3);
				switch(number)
				{
					case 1:
						insertLast(&L, alokasi(R->data));
						deleteFirst(&R);
						printf("\n\t[+] Berhasil mengembalikan Buku dari urutan pertama");	
					break;
					
					case 2:
						node = findAkhir(R);
						insertLast(&L, alokasi(node->data));
						deleteLast(&R);
						printf("\n\t[+] Berhasil mengembalikan Buku dari urutan terakhir");
					break;
					
					case 3:
						printf("\n\t[+] Tidak terjadi Pengembalian Buku");						
					break;
				}
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
