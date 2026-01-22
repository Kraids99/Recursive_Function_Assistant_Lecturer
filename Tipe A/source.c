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

address findNode(List L, str judul)
{
	if(isEmpty(L)) return NULL;
	else
	{
		if(strcmpi(L->data.judul,judul) == 0)
			return L;
		return 
			findNode(L->next, judul);
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

void insertAfter(List *L, address newNode, str prev)
{
	address p = findNode(*L, prev);
	
	if(p!=NULL)
	{
		newNode->next = p->next;
		p->next = newNode;
	}
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

void deleteByGenre(List *L, str genre)
{
	if(isEmpty(*L)) return;

    if(strcmp((*L)->data.genre, genre) == 0) 
	{
        deleteFirst(L);                     
        deleteByGenre(L, genre);           
    }
	else 
        deleteByGenre(&(*L)->next, genre);
}

void reverseList(List *L)
{
    if(*L == NULL || (*L)->next == NULL) return;

    address rest = (*L)->next; // simpan node setelah head
    reverseList(&rest); // balik sisa list
    (*L)->next->next = *L; // sambungkan node berikut ke head lama
    (*L)->next = NULL; // putuskan head lama
    *L = rest; // rest jadi head baru
}

void printSingle(address temp)
{
	printf("\n    Judul Lagu   	: %s", temp->data.judul);
	printf("\n    Genre        	: %s", temp->data.genre);
	printf("\n    Durasi Lagu 	: %d menit", temp->data.durasi);
	printf("\n  --------------------------------------\n");
}

void printSingleCount(List L, int count)
{
	printf("\n[%d] Judul Lagu		: %s", count, L->data.judul);
	printf("\n    Genre        	: %s", L->data.genre);
	printf("\n    Durasi Lagu 	: %d menit", L->data.durasi);
	printf("\n  --------------------------------------\n");
}

void printAll(List L, int count)
{
	str status;
	if(!isEmpty(L))
	{
		printf("\n[%d] Judul Lagu  	: %s", count, L->data.judul);
		printf("\n    Genre        	: %s", L->data.genre);
		printf("\n    Durasi Lagu 	: %d menit", L->data.durasi);
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

int countJudul(List L, str genre, int count)
{
	if(isEmpty(L)) return count;
	if(strcmpi(L->data.genre, genre) == 0)
		return countJudul(L->next, genre, count+1);
	else
        return countJudul(L->next, genre, count);
}

int countNodes(List L){
    if(L == NULL) return 0;
    return 1 + countNodes(L->next);
}

int randomNumber(int min, int max)
{
	return rand()%(max-min+1)+min;
}

address randomNode(List L, int index)
{
	if(L == NULL) return NULL;
	if(isOneElement(L)) return L;        
    if(index == 0) return L;          
    return randomNode(L->next, index-1);
}
