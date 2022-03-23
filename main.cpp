// ============================================================================
//									STL
// 
//	2022.3.23 ��34              ��23��34                   (1��1��)
// 
//	���� - ȣ�Ⱑ�� Ÿ�� ( callable type ) - ���� (sort)
// 
//	�ڿ��� �����ϴ� Ŭ���� - STRING - �����̳�, �ݺ���, �˰���
// 
//	ȣ�Ⱑ��Ÿ��(callable type)  ����
// ============================================================================


#include <iostream>
#include <thread>
#include "save.h"

using namespace std;

class Dog {
public : 
	
};


void jump() { cout << "jump" << endl; }
void slide() { cout << "slide" << endl; }

int main() {
	save("main.cpp");

	void (*x)(void) = jump;
	int i{};
	bool toggle = true;

	while (true) {
		x();
		this_thread::sleep_for(1s);
		if ((i++ % 3) == 0) {
			if (toggle) {
				x = slide;
				toggle = false;
			}
			else {
				x = jump;
				toggle = true;
			}
		}
	}
	
}




