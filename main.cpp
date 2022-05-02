// ============================================================================
//									STL
// 
//	2022.5.2.        월23              월23수34               8주 2일     
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
	//사전식비교 알고리즘
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	//return string(lhs.begin(),lhs.end()) < string(rhs.begin(),rhs.end());
}



int main() {
	ifstream in{ "main.cpp" };
	//[문제] 글자를 입력받아 단어의 몇번째 글자인지 출력하라
	STRING str;
	cout << "단어를 입력하세요 " << endl;
	cin >> str;
	while (true) {
		


		cout << "찾을 글자는?";

		char c;
		cin >> c;

		auto p = find(str.begin(), str.end(), c);
		if (p == str.end()) {
			cout << c << "는 없는 글자 입니다 " << endl;
		}
		else {
			//cout << c << "는 " << distance(str.begin(), p) + 1 << "번째글자 입니다" << endl;
		}
	}

	

	save("main.cpp");
}
