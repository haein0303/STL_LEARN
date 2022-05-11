// ============================================================================
//									STL
// 
//	2022.5.11.        ��34              ��23��34               8�� 2��     
// 
//  
// 
// ============================================================================


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"

using namespace std;

int main() {

//[����] "main.cpp"�� �ҹ��� ������ ���� ����϶�.

	//int alpha[26];
	//
	//char c = 'a';
	//alpha['a' - 'a']++;

	map<string, int> cim;

	ifstream in{ "main.cpp" };
	string tmp;
	while (in>>tmp) {
		cim[tmp]++;
	}

	for (const auto& a : cim) {
		cout << "[" << a.first << "] = " << a.second << endl;
	}


	save("main.cpp");
}
