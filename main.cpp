// ============================================================================
//									STL
// 
//	2022.4.27.        수34              월23수34               8주 2일     
// 
//  
// 
// ============================================================================


#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include "save.h"
#include "STRING.h"

using namespace std;




int main() {
	string str{ "The quick brown fox jumps over the lazy dog" };
	//cout << str << endl;

	//[도전] str을 sort로 정렬할 수 있게 한다.

	sort(str.begin(), str.end());
	

	for (auto i : str) {
		cout << i;
	}

	save("main.cpp");
}
