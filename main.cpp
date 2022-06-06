// ============================================================================
//									STL
// 
//	2022.6.6.        ��34              ��23��34               13�� 2��     
//
//	�˰��� - ��͵��� �ֳ� ���캻��
// 
// 
// ============================================================================


#include <iostream>
#include <concepts>
#include <string>
#include <random>
#include <format>
#include <vector>
#include <ranges>
#include <algorithm>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"
 
using namespace std;


int main() {

	save("main.cpp");

	int a[]{ 1,2,3,4,5,6,7,8,9,10 };
	//[����] 1���� �����ϴ� �ڿ������� range a���� Ȧ���� ��� �����Ͽ� ����϶�
	auto Ȧ�� = [](int n) {return n % 2; };
	auto ���� = [](int n) {return n * n; };
	for (int n : views::iota(1)
				| views::filter(Ȧ��) 
				| views::transform(����)
				| views::take(10000)
				| views::reverse
		)
	{
		cout << format("{:10}", n) << " ";
	}

}