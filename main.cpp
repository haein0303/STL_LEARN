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
#include <vector>
#include <string>
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
	//관찰 = true;
	vector<string> v;

	string word;

	cout << "Q : 입력종료" << endl;
	while (cin >> word) {
		v.push_back(word);
	}

	sort(v.begin(), v.end());

	for (const auto& a : v) {
		cout << a << endl;
	}

}




