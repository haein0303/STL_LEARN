// ============================================================================
//									STL
// 
//	2022.5.4.        ��34              ��23��34               8�� 2��     
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
	cout << "���� - ��ü �޸� : " << a.size_bytes() << endl;
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}
	
}

void print(span<char> a) {
	cout << "����(char) - ��ü �޸� : " << a.size_bytes() << endl;
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}

}

int main() {

	STRING s{ "hello!span?" };

	//print(span<char>(s.begin(), s.end());

	save("main.cpp");
}
