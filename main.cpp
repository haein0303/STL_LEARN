// ============================================================================
//									STL
// 
//	2022.5.16.        ��23              ��23��34               8�� 2��     
// 
//  
// 
// ============================================================================


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <format>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"

using namespace std;

int main() {

//[����] e-class���� "frankenstein.txt"�� vector<string>�� �о��
	ifstream in{ "Frankenstein.txt" };
	
	vector<string> v{ istream_iterator<string>{in},{} };

	//[����] ���� ������ �ܾ� ������ ���
	map<string, int> count;
	for (string a : v) {
		count[a]++;
	}


	multimap<int, string,greater<int>> m;
	for (auto [����, ����] : count) {
		m.insert({ ����,���� });
	}

	for (auto [����, ����] : m) {
		cout << "[" << format("{:^20}",����) << "] = " << format("{:5}", ����) << endl;
	}
	

	save("main.cpp");
}
