// ============================================================================
//									STL
// 
//	2022.3.14 월34              월23수34                   (1주1일)
// 
//	많은 수의 자료를 다루는 연습
// 1. int -> class
//	  int 여러개를 파일에 저장하기
// 
// C++ 정수형 - 2바이트 이상 / 기계마다 다름
// 
// [숙제]
// 파일입출력 알아보기
// 랜덤하게 뽑아낸 1000개의 수를 파일(int 1000개.txt)에 저장하라.
// 
// ============================================================================


#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <format>
#include <random>
#include <string>
#include <string_view>

using namespace std;

random_device rd;
default_random_engine dre{rd()}; //엔진
//엔진은 용량이 크기때문에 전역으로 1회만 설정
uniform_int_distribution<> uid; //분포


//[문제] int의 최댓값을 화면에 출력하라
//[문제] 엔진과 분포를 이용하여 임의의(pseudo-random) int 값 1000개를 화면에 출력하라.


void saveNum() {
	ofstream out{ "int1000개.txt", ios::out };

	for (int i = 0; i < 1000; i++) {
		out << uid(dre) << ":  ";
	}

	cout << "파일이 정상적으로 저장되었습니다" << endl;

	out.close();

}

int main() {
	

	srand(time(NULL)); //시간값을 이용해서 랜덤의 시작값을 바꿈
	for (int i = 0; i < 1000; i++) {
		cout<<format("{:<15}", uid(dre)); // < 왼쪽정렬 / >오른쪽정렬 (기본) / ^ 가운대정렬
	}

	cout << "\n\n\n" << INT_MAX  << "\n" << 0B01111111'11111111'11111111'11111111 <<"\n" << 0x7FFFFFFF << endl;
	cout << numeric_limits<int>::max() << endl;
	
	saveNum();
	

}

