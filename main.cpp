// ============================================================================
//									STL
// 
//	2022.5.18.        ��34              ��23��34               11�� 2��     
// 

// 
// 
// ============================================================================


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include <format>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"

using namespace std;



int main() {

	save("main.cpp");
	// erase-remove idiom
	vector<int> v{ 1,2,3,4,5,6 };
	
	//v���� Ȧ���� �����Ͻÿ�
	// v.erase(remove_if(v.begin(), v.end(), [](int n) {return n % 2; }), v.end());
	// remove_if �� ���ǿ� �´� �����͸� ����� ������ �ƴ� �ڷ� �о���
	//			���ϰ��� ��������� ���� ���� �ݺ���
	// erase�� ���ؼ� ����

	//C++20������ ���� erase�Լ��� �����Ѵ�
	erase_if(v, [](int n) {return n % 2; });

	for (int n : v) {
		cout << n << endl;
	}



}
