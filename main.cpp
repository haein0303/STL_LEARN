// ============================================================================
//									STL
// 
//	2022.3.28 ��23              ��23��34                   
// 
//	�ڿ��� �����ϴ� Ŭ���� - STRING - �����̳�, �ݺ���, �˰���
// 
// [ STL ������ ] STRING Ŭ������ �ۼ��Ѵ�
//   - �ڿ��� �����ϴ� Ŭ���� (RAII)
//   - ������ ���� ������Լ��� ������ ȭ�鿡 ����� �� �ְ� �Ѵ�.
//   - ǥ�� String Ŭ������ ���۰� ���� �ڵ��Ѵ�.
//   - ��ü ������ ������ȣ�� �ο�
// ============================================================================


#include <iostream>
#include <functional>
#include "save.h"

using namespace std;

bool ����{ false };

class STRING {
public:
	char* p;
	size_t num;
	int id;
	static int gid;

	STRING(const char* str) :id{ ++gid }, num { strlen(str) }, p{ new char[num] } {
		if (����) {
			//print("������ - const char*");
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




