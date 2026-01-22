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
	str nama, kategori;
	float harga;
}Data;

typedef struct node{
	Data data;
	address next;
}Node;

void createEmpty(List *L);
int isOneElement(List L);
int isEmpty(List L);
address findNode(List L, str nama, str kategori);
address alokasi(Data data);

void insertFirst(List *L, address newNode);
void insertLast(List *L, address newNode);
void deleteFirst(List *L);
void deleteAt(List *L, address delNode);
void deleteLast(List *L);
void printAll(List L, int count);
void printSingle(address temp);
void printSingleCount(List L, int count);
void printKategori(List L, int count, str kategori);

int cekKategori(List L, str kategori);
int cekNama(List L, str nama, str kategori);

void reverseList(List *L);

int randomNumber(int min, int max);
address findAkhir(List L);
