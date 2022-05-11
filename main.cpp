// ============================================================================
//									STL
// 
//	2022.5.11.        수34              월23수34               8주 2일     
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

//[문제] "main.cpp"의 소문자 갯수를 세서 출력하라.

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
