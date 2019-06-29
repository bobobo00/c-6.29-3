#define _CRT_SECURE_NO_WARNINGS 1
#include "Hash_Table.h"
//初始化散列表
void InitHashTable(Hash_Code h){
	h->count = 0;//用户个数初始化为0
	int i = 0;
	for (i = 0; i < HASH_SIZE; i++){
		h->elem[i].tel = 0;//把散列表中的用户电话均初始化为0
	}
}
//添加用户
void Add_Person(Hash_Code h){
	if (h->count == 12){
		printf("散列表已满，无法添加\n");
		return;
	}
	person p;
	printf("请输入用户电话号码：\n");
	scanf("%u", &p.tel);
	printf("请输入用户姓名：\n");
	scanf(" %s", p.name);
	printf("请输入用户住址:\n");
	scanf("%s", p.address);
	int addr = p.tel % HASH_SIZE;//除模取余法求存储位置
	while (h->elem[addr].tel != 0){//出现冲突
		addr = (addr + 1) % HASH_SIZE;//线性探测存储位置
	}
	if (h->elem[addr].tel == 0){
		h->elem[addr] = p;//添加联系人
		h->count++;
	}
}
//查找用户
void SearchHash(Hash_Code h){
	if (h->count == 0){
		printf("表为空，无法查找！\n");
		return;
	}
	printf("请输入要查找用户的电话号码：\n");
	unsigned int tele;
	scanf("%u", &tele);
	int addr = tele%HASH_SIZE;//除模取余法求存储位置
	int temp = addr;
	while (h->elem[addr].tel != tele){//出现冲突
		addr = (addr + 1) % HASH_SIZE;//线性探测存储位置
		if (addr == temp){//当遍历到起始存储位置，则表示整个散列表已全部遍历过
			printf("不存在该用户！\n");
			return;
		}
	}
	if (h->elem[addr].tel == tele){
		printf("用户姓名：%s\n", h->elem[addr].name);
		printf("用户电话：%u\n", h->elem[addr].tel);
		printf("用户住址：%s\n", h->elem[addr].address);
	}
}
//显示全部用户信息
void Show_Person(Hash_Code h){
	if (h->count == 0){
		printf("散列表为空！\n");
		return;
	}
	printf("共有%d个用户,用户信息如下：\n", h->count);
	int i = 0;
	for (i = 0; i < HASH_SIZE; i++){
		if (h->elem[i].tel != 0){
			printf("用户姓名：%s  ", h->elem[i].name);
			printf("用户电话：%u  ", h->elem[i].tel);
			printf("用户住址：%s  ", h->elem[i].address);
			printf("\n");
		}
	}
}
//删除用户
void Delet_Pereson(Hash_Code h){
	if (h->count == 0){
		printf("表为空！\n");
		return;
	}
	printf("请输入要删除用户的电话号码：\n");
	unsigned int tele;
	scanf("%u", &tele);
	int addr = tele%HASH_SIZE;//除模取余法求存储位置
	int temp = addr;
	while (h->elem[addr].tel != tele){//出现冲突
		addr = (addr + 1) % HASH_SIZE;//线性探测存储位置
		if (addr == temp){//当遍历到起始存储位置，则表示整个散列表已全部遍历过
			printf("不存在该用户！\n");
			return;
		}
	}
	if (h->elem[addr].tel == tele){
		h->elem[addr].tel = 0;
		h->count--;
	}
}