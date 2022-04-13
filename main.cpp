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
#include <deque>
#include <vector>
#include <fstream>
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
	//[����]
	// �ҽ�.cpp ������ �ܾ deque<STRING>�� �����϶�.
	// ���� ������������ �����϶�
	// ���ĵ� ����� ����϶�

	ifstream in{ "main.cpp" };
	deque<string> d{};
	string s;
	while (in >> s) {
		d.push_front(s.data());
	}

	sort(d.begin(), d.end(), [](const string &a, const string &b){
		return a.length() > b.length();
	});

	for (const auto &a : d) {
		cout << a << endl;
	}
	
	



}
