// ============================================================================
//									STL
// 
//	2022.5.25.        수34              월23수34               12주 2일     
//
//	알고리즘 - 어떤것들이 있나 살펴본다
// 
// 
// ============================================================================


#include <iostream>
#include <vector>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"

using namespace std;

template<class iter>
long long  dist(iter b, iter e) {
	return e - b;
}

int main() {

	save("main.cpp");
	
	vector<int> v{ 1,2,3,4,5 };

	//[문제] 템플릿 함수 dist를 작성하라

	cout << dist(v.begin(), v.end()) << endl;
	cout << dist(v.end(), v.begin()) << endl;
	cout << dist(1, 100) << endl;





}
