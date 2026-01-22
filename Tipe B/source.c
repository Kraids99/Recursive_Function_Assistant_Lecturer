#include "header.h"

void createEmpty(List *L)
{
	(*L) = NULL;
}

int isOneElement(List L)
{
	return L->next == NULL;
}

int isEmpty(List L)
{
	return L == NULL;
}

address findNode(List L, str namaP, str kategori)
{
	if(isEmpty(L)) return NULL;
	else
	{
		if(strcmpi(L->data.namaP,namaP) == 0 && strcmpi(L->data.kategori,kategori) == 0)
			return L;
		return 
			findNode(L->next, namaP, kategori);
	}
}

address alokasi(Data data)
{
	address p;
	p = (Node*) malloc(sizeof(Node));
	
	p->data = data;
	p->next = NULL;
	return p;
}

void insertFirst(List *L, address newNode)
{
	newNode->next = (*L);
	(*L) = newNode;
}

void insertLast(List *L, address newNode)
{
	if(isEmpty(*L)) 
		insertFirst(L, newNode);
	else
		insertLast(&(*L)->next, newNode);
}

void deleteFirst(List *L)
{
	address del = (*L);
	
	(*L) = (*L)->next;
	free(del);
}

void deleteAt(List *L, address delNode)
{
	if((*L) == delNode)
		deleteFirst(L);
	else
		deleteAt(&(*L)->next, delNode);
}

void deleteLast(List *L)
{
	if(isOneElement(*L)) 
		deleteFirst(L);
	else 
		deleteLast(&(*L)->next);
}

void deleteStokHabis(List *L)
{
	if(isEmpty(*L)) return;

    if((*L)->data.stok == 0) 
	{
        deleteFirst(L);                     
        deleteStokHabis(L);           
    }
	else 
        deleteStokHabis(&(*L)->next);
}

void printSingle(address temp)
{
	printf("\n    Nama Produk	: %s", temp->data.namaP);
	printf("\n    Kategori	: %s", temp->data.kategori);
	printf("\n    Harga	: Rp%.2f", temp->data.harga);
	printf("\n    Stok	: %d", temp->data.stok);
	printf("\n  --------------------------------------\n");
}

void printSingleCount(List L, int count)
{
	printf("\n[%d] Nama Produk	: %s", count, L->data.namaP);
	printf("\n    Kategori	: %s", L->data.kategori);
	printf("\n    Harga	: Rp%.2f", L->data.harga);
	printf("\n    Stok	: %d", L->data.stok);
	printf("\n  --------------------------------------\n");
}

void printAll(List L, int count)
{
	str status;
	if(!isEmpty(L))
	{
		printf("\n[%d] Nama Produk	: %s", count, L->data.namaP);
		printf("\n    Kategori	: %s", L->data.kategori);
		printf("\n    Harga	: Rp%.2f", L->data.harga);
		printf("\n    Stok	: %d", L->data.stok);
		printf("\n  --------------------------------------\n");
		printAll(L->next, count+1);
	}
}

int cekStok(List L)
{
	if(isEmpty(L)) return 0;
	if(L->data.stok == 0)
		return 1;
	else
		cekStok(L->next);
}

void printStokHabis(List L, int count)
{
	str status;
	if(!isEmpty(L))
	{
		if(L->data.stok == 0){
			printf("\n[%d] Nama Produk	: %s", count, L->data.namaP);
			printf("\n    Kategori	: %s", L->data.kategori);
			printf("\n    Harga	: Rp%.2f", L->data.harga);
			printf("\n    Stok	: %d", L->data.stok);
			printf("\n  --------------------------------------\n");
			printStokHabis(L->next, count+1);
		}
	}
}

void printKategori(List L, int count, str kategori)
{
	if(isEmpty(L)) 
		return;
	if(strcmpi(L->data.kategori, kategori)==0 && L->data.stok != 0)
	{
		printSingleCount(L, count);
		printKategori(L->next, count+1, kategori);
	}
	else 
		printKategori(L->next, count, kategori);
}

int cekKategori(List L, str kategori)
{
	if(isEmpty(L)) return 0;
	if(strcmpi(L->data.kategori, kategori)==0 && L->data.stok > 0)
		return 1;
	else 
		return cekKategori(L->next, kategori);
}

int cekNamaP(List L, str namaP, str kategori)
{
	if(isEmpty(L)) return 0;
	if(strcmpi(L->data.kategori, kategori)==0 && strcmp(L->data.namaP, namaP)==0 && L->data.stok !=0)
		return 1;
	else 
		return cekNamaP(L->next, namaP, kategori);
}

address findTerbesar(List L, address temp)
{
	if(L == NULL) return temp;
	if(L->data.harga > temp->data.harga)
		temp = L;
	return findTerbesar(L->next, temp);
}

address findTerendah(List L, address temp)
{
	if(L == NULL) return temp;
	if (L->data.harga < temp->data.harga)
		temp = L;
	return findTerendah(L->next, temp);	
}

int randomNumber(int min, int max)
{
	return rand()%(max-min+1)+min;
}
