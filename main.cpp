// ============================================================================
//									STL
// 
//	2022.6.6.        수34              월23수34               13주 2일     
//
//	알고리즘 - 어떤것들이 있나 살펴본다
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
	//[문제] 1부터 시작하는 자연수에서 range a에서 홀수만 골라 제곱하여 출력하라
	auto 홀수 = [](int n) {return n % 2; };
	auto 제곱 = [](int n) {return n * n; };
	for (int n : views::iota(1)
				| views::filter(홀수) 
				| views::transform(제곱)
				| views::take(10000)
				| views::reverse
		)
	{
		cout << format("{:10}", n) << " ";
	}

}