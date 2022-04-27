// ============================================================================
//									STL
// 
//	2022.4.27.        수34              월23수34               8주 2일     
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

template <class iter>

void show(iter) {
	//[문제]iter의 category를 출력하라
	//cout << typeid(iter).name() << endl;
	cout << typeid(iterator_traits<iter>::iterator_category).name() << endl;
	
}


int main() {
	int* p = NULL;
	//반복자 종류를 출력해본다 show() : 반복자 종류를 출력한다.
	//템플릿 함수에는 뭐가 전달될지 모른다. - 알았으면 더 좋은 함수를 만들 수 있다.
	show(p);
	show(istream_iterator<char>{cin});
	show(ostream_iterator<char>{cout});



	save("main.cpp");
}
