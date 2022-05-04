// ============================================================================
//									STL
// 
//	2022.5.4.        수34              월23수34               8주 2일     
// 
//  
// 
// ============================================================================


#include <iostream>
#include <vector>
#include <algorithm>
#include <span>
#include <string>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"

using namespace std;

void print(span<int> a) {
	cout << "스팬 - 전체 메모리 : " << a.size_bytes() << endl;
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}
	
}

void print(span<char> a) {
	cout << "스팬(char) - 전체 메모리 : " << a.size_bytes() << endl;
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}

}

int main() {

	STRING s{ "hello!span?" };

	//print(span<char>(s.begin(), s.end());

	save("main.cpp");
}
