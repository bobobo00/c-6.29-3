#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define HASH_SIZE 12
#define NAME_SIZE 16
#define ADDRESS_SIZE 16

typedef struct{
	unsigned int tel;
	char name[NAME_SIZE];
	char address[ADDRESS_SIZE];
}person;

typedef struct{
	person elem[NAME_SIZE];
	int count;
}Hash,*Hash_Code;
 

void InitHashTable(Hash_Code h);
void SearchHash(Hash_Code h);
void Add_Person(Hash_Code h);
void Show_Person(Hash_Code h);
void Delet_Pereson(Hash_Code h);

#endif