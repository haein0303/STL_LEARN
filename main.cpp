// ============================================================================
//									STL
// 
//	2022.5.16.        월23              월23수34               8주 2일     
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

//[문제] e-class에서 "frankenstein.txt"를 vector<string>에 읽어라
	ifstream in{ "Frankenstein.txt" };
	
	vector<string> v{ istream_iterator<string>{in},{} };

	//[문제] 많이 출현한 단어 순으로 출력
	map<string, int> count;
	for (string a : v) {
		count[a]++;
	}


	multimap<int, string,greater<int>> m;
	for (auto [문자, 개수] : count) {
		m.insert({ 개수,문자 });
	}

	for (auto [개수, 문자] : m) {
		cout << "[" << format("{:^20}",문자) << "] = " << format("{:5}", 개수) << endl;
	}
	

	save("main.cpp");
}
