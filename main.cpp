// ============================================================================
//									STL
// 
//	2022.3.23 수34              월23수34                   (1주1일)
// 
//	오늘 - 호출가능 타입 ( callable type ) - 정렬 (sort)
// 
//	자원을 관리하는 클래스 - STRING - 컨테이너, 반복자, 알고리즘
// 
//	호출가능타입(callable type)  공부
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




