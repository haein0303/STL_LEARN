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
#include <algorithm>
#include <array>
#include <fstream>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool 관찰;

//[문제] 키보드에서 입력하는 모든 단어를 받아라
//오름차순으로 정렬한다
//결과를 출력한다.

int main() {
	save("main.cpp");

	//[문제] "소스.cpp"를 읽어 알파벳의 갯수를 다음과 같이 출력하라
	// 대소문자는 구분하지않는다.
	// [a] = 10
	// [b] = 2
	// ...
	// [z] = 1

	array<int, 26> count;

	ifstream in{ "main.cpp" };
	
	if (in) {
		cout << "file Read" << endl;

		vector<char> v{ istream_iterator<char> {in},{} };

		for (char c : v) {
			
		}
	}
	
}




