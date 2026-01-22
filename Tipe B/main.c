#include "header.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	str namaP, kategori;
	int menu, submenu, stok, number;
	float harga, total, uang;
	int jumlah;
	Data data;
	List L, R;
	char YesOrNo;
	address node, temp;
	createEmpty(&L);
	createEmpty(&R);
	
	do
	{
		system("cls");
		printf("\n\t===[ Thie Logistic ]===");
		printf("\n[1] Tambah Produk");
		printf("\n[2] Tampil Produk");
		printf("\n[3] Pembelian Produk");
		printf("\n\n\t==[ BONUS ]==");
		printf("\n[4] Memisahkan Harga Terkecil & Terbesar");
		printf("\n\n\t==[ TUGAS ]==");
		printf("\n[5] Riwayat Pembelian");
		printf("\n[6] Membersihkan Produk\n");
		printf("\n[0] Keluar");
		printf("\n>> ");scanf("%d", &menu);
		switch(menu)
		{
			case 1:
				printf("\n\t===[ Tambah Produk ]===\n");
				printf("\n\tNama Produk\t: ");fflush(stdin);gets(data.namaP);
				while(1)
				{
					printf("\n\tKategori Produk (Makanan/Pakaian/Elektronik): ");fflush(stdin);gets(data.kategori);
					if(strcmpi(data.kategori,"Makanan")!=0 && strcmpi(data.kategori,"Pakaian")!=0 && strcmpi(data.kategori,"Elektronik")!=0)
						printf("\n\t[!] Kategori Produk invalid\n");
					else break;
				}
				printf("\n\tHarga\t\t: ");scanf("%f", &data.harga);
				
				printf("\n\tStok\t\t: ");scanf("%d", &data.stok);
				
				insertLast(&L, alokasi(data));
				printf("\n\t[+] Berhasil Menambahkan Produk");
			break;
			
			case 2:
				if(isEmpty(L))
				{
					printf("\n\t[!] Data produk masih kosong");
					break;
				}
				printf("\n\t===[ Daftar Produk ]===\n");
				printAll(L, 1);
			break;
			
			case 3:
				if(isEmpty(L))
				{
					printf("\n\t[!] Data produk masih kosong");
					break;
				}
				system("cls");
				printf("\n===[ Pembelian Produk ]===\n");
				printf("\nPilih Kategori Produk yang ingin di beli (Makanan/Pakaian/Elektronik): ");fflush(stdin);gets(kategori);
				if(strcmpi(kategori,"Makanan")!=0 && strcmpi(kategori,"Pakaian")!=0 && strcmpi(kategori,"Elektronik")!=0)
				{
					printf("\n\t[!] Kategori Produk invalid\n");
					break;
				}		
				if(!cekKategori(L, kategori))
				{
					printf("\n\t[!] Kategori ini belum ada produk");
					break;
				}
				printf("\n\n===[ Daftar Produk dengan Kategori %s ]===\n", kategori);
				printKategori(L, 1, kategori);
				printf("\n\nPilih Nama Produk yang ingin dibeli : ");fflush(stdin);gets(namaP);
				if(cekNamaP(L, namaP, kategori)==1)
				{
					node = findNode(L, namaP, kategori);
					printSingle(node);
					
					while(1){
						printf("\nBerapa jumlah barang yang ingin Anda beli ? ");scanf("%d", &jumlah);
						if(jumlah > node->data.stok || jumlah <=0)
							printf ("\n\t[!] Jumlah melebihi stok yang tersedia atau invalid");
						else break;
					}
					total=jumlah*node->data.harga;
					
					printf ("\nSilahkan bayar sejumlah Rp%.2f", total);
					while(1){
						printf("\n>> ");scanf("%f", &uang);
						if(uang<total)
							printf ("\n\t[-] Saldo kurang, silahkan bayar lagi");
						else break;
					}
					printf("\n\t[+] Berhasil membayar, kembalian Rp%.2f", uang-total);
					printf("\n\n\t[*] Berhasil membeli produk");
					strcpy(data.namaP, node->data.namaP);
					strcpy(data.kategori, node->data.kategori);
					data.stok = jumlah;
					data.harga = total;		
					temp = alokasi(data);						
					insertFirst(&R, temp);
					node->data.stok-=jumlah;
				}else printf("\n\n\t[!] Produk dengan nama %s tidak ditemukan", namaP);
			break;
			
			//Bonus
			case 4:
				if(isEmpty(L))
				{
					printf("\n\t[!] Data Produk masih kosong");
					break;
				}
				printf ("\n        ===[ Harga Produk Terbesar & Terendah ]===\n");
				printf ("\n\tHarga Produk Terbesar :");
				node = findTerbesar(L, L);
				printSingle(node);
				printf ("\n\tHarga Produk Terendah :");
				node = findTerendah(L, L);
				printSingle(node);
			break;
			
			//Tugas
			case 5:
				if(isEmpty(R))
				{
					printf("\n\t[!] Riwayat Pembelian masih kosong\n");
					break;
				}
				printf("\n\t===[ Daftar Produk Yang Dibeli ]===\n");
				printAll(R, 1);
			break;
			
			case 6:
				if(isEmpty(L))
				{
					printf("\n\t[!] Data Produk masih kosong");
					break;
				}
				printf ("\n\t===[ Daftar Produk Yang Stock Habis ]===\n");
				if(cekStok(L) == 0)
				{
					printf("\n\n\t[!] Tidak ada data produk yang stoknya kosong");
					break;
				}
				else
				{
					printStokHabis(L, 1);
					printf("\n\tApakah Anda yakin ingin menghapus data produk (y/n) ? ");YesOrNo=getche();
					if(YesOrNo == 'Y' || YesOrNo == 'y')
					{
						deleteStokHabis(&L);
						printf("\n\n\t[*] Berhasil menghapus data produk");
					}
					else
					{
						printf("\n\n\t[!] Tidak jadi menghapus data produk");
					}
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
