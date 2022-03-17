// ============================================================================
//									STL
// 
//	2022.3.14 ��34              ��23��34                   (1��1��)
// 
//	���� ���� �ڷḦ �ٷ�� ����
// 1. int -> class
//	  int �������� ���Ͽ� �����ϱ�
// 
// C++ ������ - 2����Ʈ �̻� / ��踶�� �ٸ�
// 
// [����]
// ��������� �˾ƺ���
// �����ϰ� �̾Ƴ� 1000���� ���� ����(int 1000��.txt)�� �����϶�.
// 
// 
//  2022.3.16 ��34
// 
// ���Ͽ� ����� ���� ���
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
std::default_random_engine dre{rd()}; //����
//������ �뷮�� ũ�⶧���� �������� 1ȸ�� ����
std::uniform_int_distribution<> uid; //����


//[����] int�� �ִ��� ȭ�鿡 ����϶�
//[����] ������ ������ �̿��Ͽ� ������(pseudo-random) int �� 1000���� ȭ�鿡 ����϶�.



void saveNum() {
	std::ofstream out{ "int1000��.txt", std::ios::out };

	for (int i = 0; i < 1000; i++) {
		out << uid(dre) << '\t';
	}

	std::cout << "������ ���������� ����Ǿ����ϴ�" << std::endl;

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
	std::cout << "���� ū�� : " << max << std::endl;
	
	std::cout << "���� ū�� : " << *std::max_element(std::istream_iterator<int> {in}, {});

}


//[����] int 1000���� �����Ϸ��� �޸� �� ����Ʈ�� �ʿ��մϱ�?
// �� �信 �°� int�� ���Ͽ� �����ϰ� �޸� ũ�⸦ Ȯ���ϼ���?
void sizeint() {

	std::ofstream out{ "int1000��size.txt" ,std::ios::binary };
	int num{};
	for (int i{ 1 }; i <= 1000; ++i) {
		num = uid(dre);
		out.write((const char*)&num, sizeof(int));
	}	
	
	

	
}

//16��
//[����] ���Ͽ� int 1000���� vinary mode�� ���۵Ǿ���.
//���� ū���� ȭ�鿡 ����϶�.
void findandmaxsize() {
	std::ifstream in{ "int1000��size.txt",std::ios::binary };
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

//[����] ����ڰ� ���ϴ� ������ŭ int�� ������ �޸𸮸� ������
//�� �޸𸮸� 1���� �����ϴ� int ������ ä����
//�� ���� ���� ����϶�
void memorycontrol() {
	int num;
	std::cout << "��� �޸𸮸� ���Ͻʴϱ�? " << std::endl;

	std::cin >> num;

	int* mem;
	mem = new int[num];
	std::array;

	std::cout << std::endl;
}


int main() {
	

	//srand(time(NULL)); //�ð����� �̿��ؼ� ������ ���۰��� �ٲ�
//	for (int i = 0; i < 1000; i++) {
	//	std::cout<<std::format("{:<15}", uid(dre)); // < �������� / >���������� (�⺻) / ^ ���������
	//}

	//std::cout << "\n\n\n" << INT_MAX  << "\n" << 0B01111111'11111111'11111111'11111111 <<"\n" << 0x7FFFFFFF << endl;
	//std::cout << std::numeric_limits<int>::max() << std::endl;
	


	//saveNum();
	//loadNum("int1000��.txt");
	//findandmaxsize();
	
	memorycontrol();
	//save("source0314.cpp");

}

