#include <iostream>
using namespace std;
#include "method.h"



int main() {
	
	//创建通讯录
	struct Addressbooks abs;
	//初始化通讯录中人数
	abs.m_Size = 0;

	while (1) {
		menu();
		cout << "请输入操作选择：>";
		int s;
		cin >> s;

		if (s == 0) {
			cout << "欢迎下次使用！" << endl;
			break;
		}

		switch (s) {
		case 1:
			addPerson(&abs);
			break;
		case 2:
			printPerson(&abs);
			break;
		case 3:
			deletPerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			break;
		}
	}
	
	return 0;
}