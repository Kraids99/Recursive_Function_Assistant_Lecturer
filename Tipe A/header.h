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
	int durasi;
}Data;

typedef struct node{
	Data data;
	address next;
}Node;

void createEmpty(List *L);
int isOneElement(List L);
int isEmpty(List L);
address findNode(List L, str judul);
address alokasi(Data data);

void insertFirst(List *L, address newNode);
void insertAfter(List *L, address newNode, str prev);
void insertLast(List *L, address newNode);
void deleteFirst(List *L);
void deleteAt(List *L, address delNode);
void deleteLast(List *L);
void deleteByGenre(List *L, str genre);
void printAll(List L, int count);
void printSingle(address temp);
void printSingleCount(List L, int count);
void printGenre(List L, int count, str genre);

void reverseList(List *L);

int cekGenre(List L, str genre);
int cekJudul(List L, str judul, str genre);
int countJudul(List L, str genre, int count);
int countNodes(List L);

int randomNumber(int min, int max);
address randomNode(List L, int index);
