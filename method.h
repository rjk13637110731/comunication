#pragma once
#include <iostream>
using namespace std;
#define MAX 1000

//联系人结构体
struct Person
{
	string m_Name; //姓名
	int m_Sex; //性别：1男 2女
	int m_Age; //年龄
	string m_Phone; //电话
	string m_Addr; //住址
};

//通讯录的结构体
struct Addressbooks {
	//通讯录保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};

void menu();

void addPerson(struct Addressbooks * abs);

void printPerson(struct Addressbooks* abs);

void deletPerson(struct Addressbooks* abs);

int isExist(struct Addressbooks* abs, string name);

void findPerson(struct Addressbooks* abs);

void modifyPerson(struct Addressbooks* abs);

void cleanPerson(struct Addressbooks* abs);