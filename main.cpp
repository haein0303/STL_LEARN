// ============================================================================
//									STL
// 
//	2022.5.25.        ��34              ��23��34               12�� 2��     
//
//	�˰��� - ��͵��� �ֳ� ���캻��
// 
// 
// ============================================================================


#include <iostream>
#include <vector>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"

using namespace std;

template<class iter>
long long  dist(iter b, iter e) {
	return e - b;
}

int main() {

	save("main.cpp");
	
	vector<int> v{ 1,2,3,4,5 };

	//[����] ���ø� �Լ� dist�� �ۼ��϶�

	cout << dist(v.begin(), v.end()) << endl;
	cout << dist(v.end(), v.begin()) << endl;
	cout << dist(1, 100) << endl;





}
