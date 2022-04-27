// ============================================================================
//									STL
// 
//	2022.4.27.        ��34              ��23��34               8�� 2��     
// 
//  
// 
// ============================================================================


#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "save.h"
#include "STRING.h"

using namespace std;

//[����] "����.txt"��

template <class iter>

void show(iter) {
	//[����]iter�� category�� ����϶�
	//cout << typeid(iter).name() << endl;
	cout << typeid(iterator_traits<iter>::iterator_category).name() << endl;
	
}


int main() {
	int* p = NULL;
	//�ݺ��� ������ ����غ��� show() : �ݺ��� ������ ����Ѵ�.
	//���ø� �Լ����� ���� ���޵��� �𸥴�. - �˾����� �� ���� �Լ��� ���� �� �ִ�.
	show(p);
	show(istream_iterator<char>{cin});
	show(ostream_iterator<char>{cout});



	save("main.cpp");
}
