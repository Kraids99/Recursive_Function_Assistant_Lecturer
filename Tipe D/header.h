#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef char str[100];

typedef struct node *address;
typedef struct node *List;

typedef struct{
	str judul, genre;
	int tahunTerbit;
}Data;

typedef struct node{
	Data data;
	address next;
}Node;

void createEmpty(List *L);
int isOneElement(List L);
int isEmpty(List L);
address findNode(List L, str judul, str genre);
address alokasi(Data data);

void insertFirst(List *L, address newNode);
void insertLast(List *L, address newNode);
void deleteFirst(List *L);
void deleteAt(List *L, address delNode);
void deleteLast(List *L);
void printAll(List L, int count);
void printSingle(address temp);
void printSingleCount(List L, int count);
void printGenre(List L, int count, str genre);

int cekGenre(List L, str genre);
int cekJudul(List L, str judul, str genre);

void printTahunatas(List L, int count);
void printTahunbawah(List L, int count);

int randomNumber(int min, int max);
address findAkhir(List L);
