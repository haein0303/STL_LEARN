// ============================================================================
//									STL
// 
//	2022.5.4.        수34              월23수34               8주 2일     
// 
//  
// 
// ============================================================================


#include <iostream>
#include <set>
#include <random>
#include <array>
#include <vector>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"

using namespace std;

default_random_engine re1;
uniform_int_distribution<int> uidAlpha{ 'a','z' };
uniform_int_distribution<int> uidNum{ 1,10000 };

class Dog {
	string name;//10글자 소문자
	int num;    //1~10000사이
public:
	Dog() {
		for (int i = 0; i < 10; ++i) {
			name += uidAlpha(re1);
			num = uidNum(re1);
		}
	}
	void show()const {
		cout << name << " - " << num << endl;
	}
};

array<Dog,1000> dogs;

int main() {

	for (const Dog& dog : dogs) {
		dog.show();
	}

	set<Dog> s{ dogs.begin(),dogs.end() };

	for (const Dog& dog : s) {
		dog.show();
	}

	save("main.cpp");
}
