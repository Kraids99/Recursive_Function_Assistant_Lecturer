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

address findNode(List L, str judul, str genre)
{
	if(isEmpty(L)) return NULL;
	else
	{
		if(strcmpi(L->data.judul,judul) == 0 && strcmpi(L->data.genre, genre) == 0)
			return L;
		return 
			findNode(L->next, judul, genre);
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

void printSingle(address temp)
{
	printf("\n    Judul Buku   	: %s", temp->data.judul);
	printf("\n    Genre        	: %s", temp->data.genre);
	printf("\n    Tahun terbit 	: %d", temp->data.tahunTerbit);
	printf("\n  --------------------------------------\n");
}

void printSingleCount(List L, int count)
{
	printf("\n[%d] Judul Buku   	: %s", count, L->data.judul);
	printf("\n    Genre        	: %s", L->data.genre);
	printf("\n    Tahun terbit 	: %d", L->data.tahunTerbit);
	printf("\n  --------------------------------------\n");
}

void printAll(List L, int count)
{
	str status;
	if(!isEmpty(L))
	{
		printf("\n[%d] Judul Buku   	: %s", count, L->data.judul);
		printf("\n    Genre        	: %s", L->data.genre);
		printf("\n    Tahun terbit 	: %d", L->data.tahunTerbit);
		printf("\n  --------------------------------------\n");
		printAll(L->next, count+1);
	}
}

void printGenre(List L, int count, str genre)
{
	if(isEmpty(L)) 
		return;
	if(strcmpi(L->data.genre, genre)==0)
	{
		printSingleCount(L, count);
		printGenre(L->next, count+1, genre);
	}
	else 
		printGenre(L->next, count, genre);
}

int cekGenre(List L, str genre)
{
	if(isEmpty(L)) return 0;
	if(strcmpi(L->data.genre, genre)==0)
		return 1;
	else 
		return cekGenre(L->next, genre);
}

int cekJudul(List L, str judul, str genre)
{
	if(isEmpty(L)) return 0;
	if(strcmpi(L->data.genre, genre)==0 && strcmp(L->data.judul, judul)==0)
		return 1;
	else 
		return cekJudul(L->next, judul, genre);
}

void printTahunatas(List L, int count)
{
	if(isEmpty(L)) return;
	if(L->data.tahunTerbit >= 2000)
	{
		printSingleCount(L, count);
		printTahunatas(L->next, count+1);
	}
	else 
		printTahunatas(L->next, count);
}

void printTahunbawah(List L, int count)
{
	if(isEmpty(L)) return;
	if(L->data.tahunTerbit < 2000)
	{
		printSingleCount(L, count);
		printTahunbawah(L->next, count+1);
	}
	else 
		printTahunbawah(L->next, count);
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
