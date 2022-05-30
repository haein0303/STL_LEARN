// ============================================================================
//									STL
// 
//	2022.5.25.        ��34              ��23��34               12�� 2��     
//
//	�˰��� - ��͵��� �ֳ� ���캻��
// 
// 
// ============================================================================


#include <iostream>
#include <string>
#include <random>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"

using namespace std;

default_random_engine dre;
uniform_int_distribution<> uid(1,100);
uniform_int_distribution<> uidName{ 'a','z' };
struct Dog {
	string name;
	int n;
	Dog() {
		n = uid(dre);
		for (int i = 0; i < 5; ++i) {
			name += uidName(dre);
		}
	}
};
int main() {

	save("main.cpp");
	
	vector<Dog> v(100);

	ranges::sort(v, {}, &Dog::n);

	for (auto a : v) {
		cout << a.name << " - " << a.n << endl;
	}




}