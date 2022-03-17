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
// 
//  2022.3.16 수34
// 
// 파일에 저장된 파일 출력
// ============================================================================


#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <format>
#include <random>
#include <string>
#include <string_view>
#include <array>
#include "save.h"


std::random_device rd;
std::default_random_engine dre{rd()}; //엔진
//엔진은 용량이 크기때문에 전역으로 1회만 설정
std::uniform_int_distribution<> uid; //분포


//[문제] int의 최댓값을 화면에 출력하라
//[문제] 엔진과 분포를 이용하여 임의의(pseudo-random) int 값 1000개를 화면에 출력하라.



void saveNum() {
	std::ofstream out{ "int1000개.txt", std::ios::out };

	for (int i = 0; i < 1000; i++) {
		out << uid(dre) << '\t';
	}

	std::cout << "파일이 정상적으로 저장되었습니다" << std::endl;

	out.close();

}

void loadNum(std::string_view fname) {
	std::ifstream in{ fname.data()};
	int max=0;
	int num;
	for (int i = 0; i < 1000; i++) {
		in >> num;
		if (max < num) {
			max = num;
		}
		std::cout << num<<'\t';
	}
	std::cout << "가장 큰수 : " << max << std::endl;
	
	std::cout << "가장 큰수 : " << *std::max_element(std::istream_iterator<int> {in}, {});

}


//[문제] int 1000개를 저장하려면 메모리 몇 바이트가 필요합니까?
// 이 답에 맞게 int를 파일에 저장하고 메모리 크기를 확인하세요?
void sizeint() {

	std::ofstream out{ "int1000개size.txt" ,std::ios::binary };
	int num{};
	for (int i{ 1 }; i <= 1000; ++i) {
		num = uid(dre);
		out.write((const char*)&num, sizeof(int));
	}	
	
	

	
}

//16일
//[문제] 파일에 int 1000개가 vinary mode로 제작되었다.
//가장 큰값을 화면에 출력하라.
void findandmaxsize() {
	std::ifstream in{ "int1000개size.txt",std::ios::binary };
	int n;
	int max{};
	for (int i{}; i < 1001; ++i) {
		in.read((char*)&n, sizeof(n));
		if (max < n) {
			max = n;
		}
	}
	std::cout << max << std::endl;

	std::array<int,4000> num;
	int maxn{};
	in.read((char*)num.data(), sizeof(num) * 1000);
	for (int num : num) {
		if (maxn < num) {
			maxn = num;
		}
	}
	std::cout << maxn << std::endl;
}

//[문제] 사용자가 원하는 갯수만큼 int를 저장할 메모리를 만들어라
//그 메모리를 1부터 증가하는 int 값으로 채워라
//다 더한 값을 출력하라
void memorycontrol() {
	int num;
	std::cout << "몇개의 메모리를 원하십니까? " << std::endl;

	std::cin >> num;

	int* mem;
	mem = new int[num];
	std::array;

	std::cout << std::endl;
}


int main() {
	

	//srand(time(NULL)); //시간값을 이용해서 랜덤의 시작값을 바꿈
//	for (int i = 0; i < 1000; i++) {
	//	std::cout<<std::format("{:<15}", uid(dre)); // < 왼쪽정렬 / >오른쪽정렬 (기본) / ^ 가운대정렬
	//}

	//std::cout << "\n\n\n" << INT_MAX  << "\n" << 0B01111111'11111111'11111111'11111111 <<"\n" << 0x7FFFFFFF << endl;
	//std::cout << std::numeric_limits<int>::max() << std::endl;
	


	//saveNum();
	//loadNum("int1000개.txt");
	//findandmaxsize();
	
	memorycontrol();
	//save("source0314.cpp");

}

