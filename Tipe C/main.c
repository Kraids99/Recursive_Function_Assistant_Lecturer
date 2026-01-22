#include "header.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    str nama, kategori;
    int menu, submenu, number;
    float  harga;
    Data data;
    List L, R;
    char YesOrNo;
    address node;
    createEmpty(&L);
    createEmpty(&R);
    
    do
    {
        system("cls");
        printf("\n\t===[ Liang Resto ]===");
        printf("\n[1] Tambah Menu");
        printf("\n[2] Tampil Menu");
        printf("\n[3] Hapus Menu");
        printf("\n\n\t==[ BONUS ]==");
        printf("\n[4] Reverse List Menu");
        printf("\n\n\t==[ TUGAS ]==");
        printf("\n[5] Riwayat Hapus Menu");
        printf("\n[6] Pengembalian Menu\n");
        printf("\n[0] Keluar");
        printf("\n>> ");scanf("%d", &menu);
        switch(menu)
        {
            case 1:
                printf("\n\t===[ Tambah Menu ]===\n");
                printf("\n\tNama Menu\t: ");fflush(stdin);gets(data.nama);
                while(1)
                {
                    printf("\n\tKategori Menu (Makanan/Minuman): ");fflush(stdin);gets(data.kategori);
                    if(strcmpi(data.kategori,"Makanan")!=0 && strcmpi(data.kategori,"Minuman")!=0)
                        printf("\n\t[!] Kategori Menu invalid\n");
                    else break;
                }
                printf("\n\tHarga Menu\t: ");scanf("%f", &data.harga);
                insertFirst(&L, alokasi(data));
                printf("\n\t[+] Berhasil Menambahkan Menu");
            break;
            
            case 2:
                if(isEmpty(L))
                {
                    printf("\n\t[!] Data restoran masih kosong");
                    break;
                }
                printf("\n\t===[ Daftar Menu ]===\n");
                printAll(L, 1);
            break;
            
            case 3:
                if(isEmpty(L))
                {
                    printf("\n\t[!] Data restoran masih kosong");
                    break;
                }
                system("cls");
                printf("\n===[ Penghapusan Menu ]===\n");
                printf("\nPilih Kategori Menu yang ingin di hapus (Makanan/Minuman): ");fflush(stdin);gets(kategori);
                if(strcmpi(kategori,"Makanan")!=0 && strcmpi(kategori,"Minuman")!=0)
                {
                    printf("\n\t[!] Kategori Menu invalid\n");
                    break;
                }
                if(!cekKategori(L, kategori))
                {
                    printf("\n\t[!] Kategori ini belum ada Menu");
                    break;
                }
                printf("\n\n===[ Daftar Menu dengan Kategori %s ]===\n", kategori);
                printKategori(L, 1, kategori);
                printf("\n\nPilih Nama Menu yang ingin di hapus : ");fflush(stdin);gets(nama);
                if(cekNama(L, nama, kategori)==1)
                {
                    node = findNode(L, nama, kategori);
                    printSingle(node);
                    printf("\nApakah Anda yakin ingin menghapus menu %s (y/n) ? ", nama);YesOrNo = getche();
                    if(YesOrNo == 'y')
                    {
                        insertFirst(&R, alokasi(node->data));
                        deleteAt(&L, node);
                        printf("\n\n\t[*] Berhasil menghapus menu");
                    }else printf("\n\n\t[!] Tidak jadi menghapus menu");
                }else printf("\n\n\t[!] Menu dengan nama %s tidak ditemukan", nama);
            break;
            
            //Bonus
            case 4:
                if(isEmpty(L))
                {
                    printf("\n\t[!] Data restoran masih kosong");
                    break;
                }
                printf("\n\t[!] Berhasil Mereverse List Menu");
                reverseList(&L);
            break;
            
            //Tugas
            case 5:
                if(isEmpty(R))
                {
                    printf("\n\t[!] Riwayat Penghapusan masih kosong\n");
                    break;
                }
                printf("\n\t===[ Daftar Menu Yang Dihapus ]===\n");
                printAll(R, 1);
            break;
            
            case 6:
                if(isEmpty(R))
                {
                    printf("\n\t[!] Riwayat Penghapusan masih kosong");
                    break;
                }
                number = randomNumber(1,3);
                switch(number)
                {
                    case 1:
                        insertLast(&L, alokasi(R->data));
                        deleteFirst(&R);
                        printf("\n\t[+] Berhasil mengembalikan Menu dari urutan pertama");    
                    break;
                    
                    case 2:
                        node = findAkhir(R);
                        insertLast(&L, alokasi(node->data));
                        deleteLast(&R);
                        printf("\n\t[+] Berhasil mengembalikan Menu dari urutan terakhir");
                    break;
                    
                    case 3:
                        printf("\n\t[+] Tidak terjadi Pengembalian Menu");                        
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

