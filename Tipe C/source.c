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

address findNode(List L, str nama, str kategori)
{
	if(isEmpty(L)) return NULL;
	else
	{
		if(strcmpi(L->data.nama,nama) == 0 && strcmpi(L->data.kategori, kategori) == 0)
			return L;
		return 
			findNode(L->next, nama, kategori);
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
	if((*L)== NULL)
	return;
	if(isOneElement(*L)) 
		deleteFirst(L);
	else 
		deleteLast(&(*L)->next);
}

void printSingle(address temp)
{
	printf("\n    Nama Menu      : %s", temp->data.nama);
	printf("\n    Kategori       : %s", temp->data.kategori);
	printf("\n    Harga  	   : Rp%.2f", temp->data.harga);
	printf("\n  --------------------------------------\n");
}

void printSingleCount(List L, int count)
{
	printf("\n[%d] Nama Menu      : %s", count, L->data.nama);
	printf("\n    Kategori       : %s", L->data.kategori);
	printf("\n    Harga  	   : Rp%.2f", L->data.harga);
	printf("\n  --------------------------------------\n");
}

void printAll(List L, int count)
{
	str status;
	if(!isEmpty(L))
	{
		printf("\n[%d] Nama Menu      : %s", count, L->data.nama);
		printf("\n    Kategori       : %s", L->data.kategori);
		printf("\n    Harga  	   : Rp%.2f", L->data.harga);
		printf("\n  --------------------------------------\n");
		printAll(L->next, count+1);
	}
}

void printKategori(List L, int count, str kategori)
{
	if(isEmpty(L)) 
		return;
	if(strcmpi(L->data.kategori, kategori)==0)
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
	if(strcmpi(L->data.kategori, kategori)==0)
		return 1;
	else 
		return cekKategori(L->next, kategori);
}

int cekNama(List L, str nama, str kategori)
{
	if(isEmpty(L)) return 0;
	if(strcmpi(L->data.kategori, kategori)==0 && strcmp(L->data.nama, nama)==0)
		return 1;
	else 
		return cekNama(L->next, nama, kategori);
}

//void reverseList(List *reverse, List L){
//	if(isEmpty(L)){
//		return;
//	} else{
//		address temp = alokasi(L->data);
//		insertFirst(reverse, temp);
//		reverseList(reverse, L->next);
//	}
//}

void reverseList(List *L)
{
    if (*L == NULL || (*L)->next == NULL) return;

    address rest = (*L)->next;     // simpan node setelah head
    reverseList(&rest);              // balik sisa list
    (*L)->next->next = *L;       // sambungkan node berikut ke head lama
    (*L)->next = NULL;           // putuskan head lama
    *L = rest;                   // rest jadi head baru
}

address findAkhir(List L)
{
    if(isEmpty(L)) 
		return NULL;       
    if(L->next == NULL) 
		return L;     
    return 
		findAkhir(L->next);       
}

int randomNumber(int min, int max)
{
	return rand()%(max-min+1)+min;
}
