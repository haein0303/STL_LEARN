// ============================================================================
//									STL
// 
//	2022.5.2.        ��23              ��23��34               8�� 2��     
// 
//  
// 
// ============================================================================


#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "save.h"
#include "STRING.h"

using namespace std;

bool operator< (const STRING& lhs, const STRING& rhs) {
	//�����ĺ� �˰���
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	//return string(lhs.begin(),lhs.end()) < string(rhs.begin(),rhs.end());
}



int main() {
	ifstream in{ "main.cpp" };
	//[����] ���ڸ� �Է¹޾� �ܾ��� ���° �������� ����϶�
	STRING str;
	cout << "�ܾ �Է��ϼ��� " << endl;
	cin >> str;
	while (true) {
		


		cout << "ã�� ���ڴ�?";

		char c;
		cin >> c;

		auto p = find(str.begin(), str.end(), c);
		if (p == str.end()) {
			cout << c << "�� ���� ���� �Դϴ� " << endl;
		}
		else {
			//cout << c << "�� " << distance(str.begin(), p) + 1 << "��°���� �Դϴ�" << endl;
		}
	}

	

	save("main.cpp");
}
