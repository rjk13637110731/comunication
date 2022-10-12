#include <iostream>
using namespace std;
#include "method.h"

//查询人是否存在
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
	cout << "*********** 1.添加联系人 ************" << endl;
	cout << "*********** 2.显示联系人 ************" << endl;
	cout << "*********** 3.删除联系人 ************" << endl;
	cout << "*********** 4.查找联系人 ************" << endl;
	cout << "*********** 5.修改联系人 ************" << endl;
	cout << "*********** 6.清空联系人 ************" << endl;
	cout << "*********** 0.退出通讯录 ************" << endl;
	cout << "*************************************" << endl;
}

//添加联系人信息
void addPerson(struct Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	cout << "请输入姓名：>";
	string name;
	cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;
	cout << "请输入性别：（1-男；2-女）>";
	int sex = 0;
	while (1) {
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->personArray[abs->m_Size].m_Sex = sex;
			break;
		}
		cout << "输入有误，请重新输入";
	}

	//年龄
	cout << "请输入年龄：>";
	int age = 0;
	cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;

	//联系电话
	cout << "请输入联系电话：>";
	string phone = "";
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;

	//家庭住址
	cout << "请输入家庭住址：>";
	string address;
	cin >> address;
	abs->personArray[abs->m_Size].m_Addr = address;

	//更新通讯录人数
	abs->m_Size++;

	cout << "添加成功" << endl;
	system("pause");
	system("cls");//清屏操作
}

//打印联系人信息
void printPerson(struct Addressbooks* abs) {
	for (int i = 0; i < abs->m_Size;i++) {
		cout << "第" << i + 1 << "个联系人信息：" << endl;
		cout << "姓名：" << abs->personArray[i].m_Name << "\t";
		cout << "性别：" << ((abs->personArray[i].m_Sex == 1) ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[i].m_Age << "\t"; 
		cout << "电话：" << abs->personArray[i].m_Phone << "\t";
		cout << "住址：" << abs->personArray[i].m_Addr << endl;
	}

	system("pause");
	system("cls");//清屏操作
}

//删除联系人
void deletPerson(struct Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "通讯录里没有联系人" << endl;
		return;
	}

	string name;
	cout <<"请输入要删除的联系人姓名：>";
	cin >> name;
	int num = isExist(abs, name);
	if (num != -1) {
		for (int i = num; i < abs->m_Size;i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功！" << endl;
	}else{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

//查找人
void findPerson(struct Addressbooks* abs) {
	cout << "请输入要查询人的姓名：>";
	string name;
	cin >> name;
	int num = isExist(abs,name);
	if (num != -1) {
		cout << "查询的联系人信息：" << endl;
		cout << "姓名：" << abs->personArray[num].m_Name << "\t";
		cout << "性别：" << ((abs->personArray[num].m_Sex == 1) ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[num].m_Age << "\t";
		cout << "电话：" << abs->personArray[num].m_Phone << "\t";
		cout << "住址：" << abs->personArray[num].m_Addr << endl;
	}

	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入要修改人的姓名：>";
	string name;
	cin >> name;
	int num = isExist(abs, name);
	if (num != -1) {
		cout << "请输入姓名：>";
		string name;
		cin >> name;
		abs->personArray[num].m_Name = name;
		cout << "请输入性别：（1-男；2-女）>";
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[num].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：>";
		int age = 0;
		cin >> age;
		abs->personArray[num].m_Age = age;

		//联系电话
		cout << "请输入联系电话：>";
		string phone = "";
		cin >> phone;
		abs->personArray[num].m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址：>";
		string address;
		cin >> address;
		abs->personArray[num].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功！" << endl;
	}else{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}