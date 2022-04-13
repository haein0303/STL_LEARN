// ============================================================================
//									STL
// 
//	2022.4.4. 월23              월23수34                   
// 
// 컨테이너 - 다른객체를 저장하는 객체
// sequence Container
//   - array    유일하게 크기가 컴파일 타임에 결정
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

extern bool 관찰;

//[문제] 키보드에서 입력하는 모든 단어를 받아라
//오름차순으로 정렬한다
//결과를 출력한다.



int main() {
	save("main.cpp");
	//[문제]
	// 소스.cpp 파일의 단어를 deque<STRING>에 저장하라.
	// 길이 오름차순으로 정렬하라
	// 정렬된 결과를 출력하라

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
