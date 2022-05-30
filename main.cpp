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