// ============================================================================
//									STL
// 
//	2022.4.27.        ��34              ��23��34               8�� 2��     
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

	//[����] str�� sort�� ������ �� �ְ� �Ѵ�.

	sort(str.begin(), str.end());
	

	for (auto i : str) {
		cout << i;
	}

	save("main.cpp");
}
