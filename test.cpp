#include <iostream>
using namespace std;
#include "method.h"



int main() {
	
	//����ͨѶ¼
	struct Addressbooks abs;
	//��ʼ��ͨѶ¼������
	abs.m_Size = 0;

	while (1) {
		menu();
		cout << "���������ѡ��>";
		int s;
		cin >> s;

		if (s == 0) {
			cout << "��ӭ�´�ʹ�ã�" << endl;
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
			cout << "�����������������룡" << endl;
			break;
		}
	}
	
	return 0;
}