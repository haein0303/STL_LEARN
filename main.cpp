// ============================================================================
//									STL
// 
//	2022.3.28 월23              월23수34                   
// 
//	자원을 관리하는 클래스 - STRING - 컨테이너, 반복자, 알고리즘
// 
// [ STL 관찰용 ] STRING 클래스를 작성한다
//   - 자원을 관리하는 클래스 (RAII)
//   - 관찰을 위해 스페셜함수의 동작을 화면에 출력할 수 있게 한다.
//   - 표준 String 클래스의 동작과 같이 코딩한다.
//   - 객체 생성시 고유번호를 부여
// ============================================================================


#include <iostream>
#include <functional>
#include "save.h"

using namespace std;

bool 관찰{ false };

class STRING {
public:
	char* p;
	size_t num;
	int id;
	static int gid;

	STRING(const char* str) :id{ ++gid }, num { strlen(str) }, p{ new char[num] } {
		if (관찰) {
			//print("생성자 - const char*");
		}
		memcpy(p, str, num);
	}
	~STRING() {
		delete[] p;
	}

	void operator()(char const *str) {
		
	}
	friend ostream& operator<<  (ostream&, const STRING&);
};

ostream& operator<<(ostream& os, const STRING& str) {
	for (int i{}; i < str.num; i++) {
		os << str.p[i];
	}
	return os;
}

int STRING::gid{};

int main() {
	STRING a{"2022. 3. 28. "};
	STRING b{ "STL" };

	cout << a << b << endl;
	cout << typeid("2022. 3. 28. ").name() << endl;

	save("main.cpp");
}




