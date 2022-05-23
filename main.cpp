// ============================================================================
//									STL
// 
//	2022.5.18.        수34              월23수34               11주 2일     
// 

// 
// 
// ============================================================================


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include <format>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"

using namespace std;



int main() {

	save("main.cpp");
	// erase-remove idiom
	vector<int> v{ 1,2,3,4,5,6 };
	
	//v에서 홀수를 삭제하시오
	// v.erase(remove_if(v.begin(), v.end(), [](int n) {return n % 2; }), v.end());
	// remove_if 는 조건에 맞는 데이터를 지우는 연산이 아닌 뒤로 밀어줌
	//			리턴값은 쓸모없어진 값의 시작 반복자
	// erase를 통해서 지움

	//C++20에서는 전역 erase함수를 제공한다
	erase_if(v, [](int n) {return n % 2; });

	for (int n : v) {
		cout << n << endl;
	}



}
