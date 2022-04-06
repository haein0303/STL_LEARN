// ============================================================================
//									STL
// 
//	2022.4.4. ��23              ��23��34                   
// 
// �����̳� - �ٸ���ü�� �����ϴ� ��ü
// sequence Container
//   - array    �����ϰ� ũ�Ⱑ ������ Ÿ�ӿ� ����
//   - vector   dynamic array 
// ============================================================================


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

//[����] Ű���忡�� �Է��ϴ� ��� �ܾ �޾ƶ�
//������������ �����Ѵ�
//����� ����Ѵ�.

int main() {
	save("main.cpp");
	//���� = true;
	vector<string> v;

	string word;

	cout << "Q : �Է�����" << endl;
	while (cin >> word) {
		v.push_back(word);
	}

	sort(v.begin(), v.end());

	for (const auto& a : v) {
		cout << a << endl;
	}

}




