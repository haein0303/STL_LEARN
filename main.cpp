// ============================================================================
//									STL
// 
//	2022.4.18. ��23              ��23��34                   
// 
//
// 
// ============================================================================


#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "save.h"
#include "STRING.h"

using namespace std;

//[����] "����.txt"��

int main() {
	save("main.cpp");

	ifstream in{ "����.txt" };
	
	list<string> cont;
	string str;
	
	cout << "����Ʈ�� ũ�� - " << sizeof(list<string>) << endl;

	while (in >> str) {
		cont.push_back(str);
	}


	auto p = find(cont.begin(), cont.end(), string{ "space" });
	int step{};
	auto beg = cont.begin();

	
	cout << "���������� " << distance(cont.begin(), p) + 1 << "��° �ܾ���" << endl;
	//����
	//cont�� ascending order�� �����϶�
	//���ĵ� ����� �տ������� 10���� ȭ�� ����϶�

	cont.sort([](const string& a, const string& b) {return a > b; });
	
	p = find(cont.begin(), cont.end(), string{ "space" });
	cout << "�����Ŀ��� " << distance(cont.begin(), p) + 1 << "��° �ܾ���" << endl;
	
	copy_if(cont.begin(), cont.end(), ostream_iterator<string>{cout,"\n"}, [](const string& a) {
		return a.size() == 5; });

}
