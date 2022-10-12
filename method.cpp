#include <iostream>
using namespace std;
#include "method.h"

//��ѯ���Ƿ����
int isExist(struct Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size;i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

void menu() {
	cout << "*************************************" << endl;
	cout << "*********** 1.�����ϵ�� ************" << endl;
	cout << "*********** 2.��ʾ��ϵ�� ************" << endl;
	cout << "*********** 3.ɾ����ϵ�� ************" << endl;
	cout << "*********** 4.������ϵ�� ************" << endl;
	cout << "*********** 5.�޸���ϵ�� ************" << endl;
	cout << "*********** 6.�����ϵ�� ************" << endl;
	cout << "*********** 0.�˳�ͨѶ¼ ************" << endl;
	cout << "*************************************" << endl;
}

//�����ϵ����Ϣ
void addPerson(struct Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	cout << "������������>";
	string name;
	cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;
	cout << "�������Ա𣺣�1-�У�2-Ů��>";
	int sex = 0;
	while (1) {
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->personArray[abs->m_Size].m_Sex = sex;
			break;
		}
		cout << "������������������";
	}

	//����
	cout << "���������䣺>";
	int age = 0;
	cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;

	//��ϵ�绰
	cout << "��������ϵ�绰��>";
	string phone = "";
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;

	//��ͥסַ
	cout << "�������ͥסַ��>";
	string address;
	cin >> address;
	abs->personArray[abs->m_Size].m_Addr = address;

	//����ͨѶ¼����
	abs->m_Size++;

	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");//��������
}

//��ӡ��ϵ����Ϣ
void printPerson(struct Addressbooks* abs) {
	for (int i = 0; i < abs->m_Size;i++) {
		cout << "��" << i + 1 << "����ϵ����Ϣ��" << endl;
		cout << "������" << abs->personArray[i].m_Name << "\t";
		cout << "�Ա�" << ((abs->personArray[i].m_Sex == 1) ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[i].m_Age << "\t"; 
		cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[i].m_Addr << endl;
	}

	system("pause");
	system("cls");//��������
}

//ɾ����ϵ��
void deletPerson(struct Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼��û����ϵ��" << endl;
		return;
	}

	string name;
	cout <<"������Ҫɾ������ϵ��������>";
	cin >> name;
	int num = isExist(abs, name);
	if (num != -1) {
		for (int i = num; i < abs->m_Size;i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ���" << endl;
	}else{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

//������
void findPerson(struct Addressbooks* abs) {
	cout << "������Ҫ��ѯ�˵�������>";
	string name;
	cin >> name;
	int num = isExist(abs,name);
	if (num != -1) {
		cout << "��ѯ����ϵ����Ϣ��" << endl;
		cout << "������" << abs->personArray[num].m_Name << "\t";
		cout << "�Ա�" << ((abs->personArray[num].m_Sex == 1) ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[num].m_Age << "\t";
		cout << "�绰��" << abs->personArray[num].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[num].m_Addr << endl;
	}

	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks* abs) {
	cout << "������Ҫ�޸��˵�������>";
	string name;
	cin >> name;
	int num = isExist(abs, name);
	if (num != -1) {
		cout << "������������>";
		string name;
		cin >> name;
		abs->personArray[num].m_Name = name;
		cout << "�������Ա𣺣�1-�У�2-Ů��>";
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[num].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		cout << "���������䣺>";
		int age = 0;
		cin >> age;
		abs->personArray[num].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��>";
		string phone = "";
		cin >> phone;
		abs->personArray[num].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��>";
		string address;
		cin >> address;
		abs->personArray[num].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ���" << endl;
	}else{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

//�����ϵ��
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}