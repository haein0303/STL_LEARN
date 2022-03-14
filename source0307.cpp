// ============================================================================
//									STL
// 
//	2022.3.7 월34              월23수34                   (1주1일)
// 
//	C++ 복습
// 
// 
// ============================================================================
#include<iostream>


template <class T> // typename or class 중 선택
void change_T(T& a, T& b) { //탬플릿은 선언과 정의를 동시에 진행
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
	Dog(std::string str, int age) :name{ str }, age{ age } { }
	friend std::ostream& operator<< (std::ostream&, const Dog&);

	operator int() {
		return local_num;
	}
};

std::ostream& operator<<(std::ostream& os, const Dog& dog) {
	os << dog.local_num;
	return os;
}


void change(auto& a, auto& b) {
	auto tmp{ b };
	b = a;
	a = tmp;
}

/*int main()
{

	using namespace std::literals;
	//	cout << "string Size : " << sizeof(string) << endl;
	//	cout << "string_view Size : " << sizeof(string_view) << endl;
	Dog a{ 1 };
	Dog b{ 2 };
	std::string c = "STL";
	std::string d = "C++";
	Dog e{ "코코",3 };
	Dog f{ "댕댕",5 };

	change(a, b);
	change(c, d);
	change(e, f);

	std::cout << " a : "s << a << " b : "s << b << std::endl;
	std::cout << " c : " << c << " d : " << d << std::endl;
	std::cout << " e : name : " << e.name << " age : " << e.age << std::endl;
	std::cout << " f : name : " << f.name << " age : " << f.age << std::endl;

	save("save.h");
	save("save.cpp");
	save("main.cpp");
}
*/