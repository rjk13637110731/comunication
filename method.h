#pragma once
#include <iostream>
using namespace std;
#define MAX 1000

//��ϵ�˽ṹ��
struct Person
{
	string m_Name; //����
	int m_Sex; //�Ա�1�� 2Ů
	int m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //סַ
};

//ͨѶ¼�Ľṹ��
struct Addressbooks {
	//ͨѶ¼�������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
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