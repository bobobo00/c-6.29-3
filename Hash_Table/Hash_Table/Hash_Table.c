#define _CRT_SECURE_NO_WARNINGS 1
#include "Hash_Table.h"
//��ʼ��ɢ�б�
void InitHashTable(Hash_Code h){
	h->count = 0;//�û�������ʼ��Ϊ0
	int i = 0;
	for (i = 0; i < HASH_SIZE; i++){
		h->elem[i].tel = 0;//��ɢ�б��е��û��绰����ʼ��Ϊ0
	}
}
//����û�
void Add_Person(Hash_Code h){
	if (h->count == 12){
		printf("ɢ�б��������޷����\n");
		return;
	}
	person p;
	printf("�������û��绰���룺\n");
	scanf("%u", &p.tel);
	printf("�������û�������\n");
	scanf(" %s", p.name);
	printf("�������û�סַ:\n");
	scanf("%s", p.address);
	int addr = p.tel % HASH_SIZE;//��ģȡ�෨��洢λ��
	while (h->elem[addr].tel != 0){//���ֳ�ͻ
		addr = (addr + 1) % HASH_SIZE;//����̽��洢λ��
	}
	if (h->elem[addr].tel == 0){
		h->elem[addr] = p;//�����ϵ��
		h->count++;
	}
}
//�����û�
void SearchHash(Hash_Code h){
	if (h->count == 0){
		printf("��Ϊ�գ��޷����ң�\n");
		return;
	}
	printf("������Ҫ�����û��ĵ绰���룺\n");
	unsigned int tele;
	scanf("%u", &tele);
	int addr = tele%HASH_SIZE;//��ģȡ�෨��洢λ��
	int temp = addr;
	while (h->elem[addr].tel != tele){//���ֳ�ͻ
		addr = (addr + 1) % HASH_SIZE;//����̽��洢λ��
		if (addr == temp){//����������ʼ�洢λ�ã����ʾ����ɢ�б���ȫ��������
			printf("�����ڸ��û���\n");
			return;
		}
	}
	if (h->elem[addr].tel == tele){
		printf("�û�������%s\n", h->elem[addr].name);
		printf("�û��绰��%u\n", h->elem[addr].tel);
		printf("�û�סַ��%s\n", h->elem[addr].address);
	}
}
//��ʾȫ���û���Ϣ
void Show_Person(Hash_Code h){
	if (h->count == 0){
		printf("ɢ�б�Ϊ�գ�\n");
		return;
	}
	printf("����%d���û�,�û���Ϣ���£�\n", h->count);
	int i = 0;
	for (i = 0; i < HASH_SIZE; i++){
		if (h->elem[i].tel != 0){
			printf("�û�������%s  ", h->elem[i].name);
			printf("�û��绰��%u  ", h->elem[i].tel);
			printf("�û�סַ��%s  ", h->elem[i].address);
			printf("\n");
		}
	}
}
//ɾ���û�
void Delet_Pereson(Hash_Code h){
	if (h->count == 0){
		printf("��Ϊ�գ�\n");
		return;
	}
	printf("������Ҫɾ���û��ĵ绰���룺\n");
	unsigned int tele;
	scanf("%u", &tele);
	int addr = tele%HASH_SIZE;//��ģȡ�෨��洢λ��
	int temp = addr;
	while (h->elem[addr].tel != tele){//���ֳ�ͻ
		addr = (addr + 1) % HASH_SIZE;//����̽��洢λ��
		if (addr == temp){//����������ʼ�洢λ�ã����ʾ����ɢ�б���ȫ��������
			printf("�����ڸ��û���\n");
			return;
		}
	}
	if (h->elem[addr].tel == tele){
		h->elem[addr].tel = 0;
		h->count--;
	}
}