// ============================================================================
//									STL
// 
//	2022.4.18. 월23              월23수34                   
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

//[문제] "연습.txt"를

int main() {
	save("main.cpp");

	ifstream in{ "연습.txt" };
	
	list<string> cont;
	string str;
	
	cout << "리스트의 크기 - " << sizeof(list<string>) << endl;

	while (in >> str) {
		cont.push_back(str);
	}


	auto p = find(cont.begin(), cont.end(), string{ "space" });
	int step{};
	auto beg = cont.begin();

	
	cout << "정렬전에는 " << distance(cont.begin(), p) + 1 << "번째 단어라네" << endl;
	//문제
	//cont를 ascending order로 정렬하라
	//정렬된 결과를 앞에서부터 10개만 화면 출력하라

	cont.sort([](const string& a, const string& b) {return a > b; });
	
	p = find(cont.begin(), cont.end(), string{ "space" });
	cout << "정렬후에는 " << distance(cont.begin(), p) + 1 << "번째 단어라네" << endl;
	
	copy_if(cont.begin(), cont.end(), ostream_iterator<string>{cout,"\n"}, [](const string& a) {
		return a.size() == 5; });

}
