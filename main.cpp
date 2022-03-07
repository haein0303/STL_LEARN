// ============================================================================
//									STL
// 
//	2022.3.7 岿34              岿23荐34                   (1林1老)
// 
//	C++ 汗嚼
// 
// 
// ============================================================================

#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include "playground.h"
#include "save.h"

template <class T>
void change_T(T& a, T& b) {
	T tmp{ a };
	a = b;
	b = tmp;
}


class Dog {
public:
	int local_num;
	std::string name;
	int age;
public:
	Dog(int n) : local_num{ n } {	}
	Dog(std::string str, int age) :name{ str }, age{age} { }
	friend std::ostream& operator<< (std::ostream&, const Dog&);
	
	operator int() {
		return local_num;
	}
};

std::ostream& operator<<(std::ostream& os , const Dog& dog) {
	os << dog.local_num;
	return os;
}


void change(auto& a, auto& b) {
	auto tmp{ b };
	b = a;
	a = tmp;
}


int main()
{
	//	cout << "string Size : " << sizeof(string) << endl;
	//	cout << "string_view Size : " << sizeof(string_view) << endl;
	Dog a{ 1 };
	Dog b{ 2 };
	std::string c = "STL";
	std::string d = "C++";
	Dog e{ "内内",3 };
	Dog f{ "大大",5 };

	change(a, b);
	change(c, d);
	change(e, f);

	std::cout << " a : " << a << " b : " << b << std::endl;
	std::cout << " c : " << c << " d : " << d << std::endl;
	std::cout << " e : name : " << e.name << " age : " << e.age << std::endl;
	std::cout << " f : name : " << f.name << " age : " << f.age << std::endl;

	/*save("save.h");
	save("save.cpp");
	save("main.cpp");*/
}