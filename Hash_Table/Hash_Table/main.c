#define _CRT_SECURE_NO_WARNINGS 1
#include "Hash_Table.h"
void Menue(){
	printf("______________\n");
	printf("1:����û�\n");
	printf("2:�����û�\n");
	printf("3:��ʾȫ���û���Ϣ\n");
	printf("4:ɾ���û�\n");
	printf("0���˳�\n");
}
int main(){
	Hash h;
	int num;
	InitHashTable(&h);
	int select = 0;
	int quit = 0;
	while (!quit){
		Menue();
		scanf("%d", &select);
		switch (select){
		case 1:
			Add_Person(&h);
			break;
		case 2:
			SearchHash(&h);
			break;
		case 3:
			Show_Person(&h);
			break;
		case 4:
			Delet_Pereson(&h);
			break;
		case 0:
			quit = 1;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}