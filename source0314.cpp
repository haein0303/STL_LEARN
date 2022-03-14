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
default_random_engine dre{rd()}; //����
//������ �뷮�� ũ�⶧���� �������� 1ȸ�� ����
uniform_int_distribution<> uid; //����


//[����] int�� �ִ��� ȭ�鿡 ����϶�
//[����] ������ ������ �̿��Ͽ� ������(pseudo-random) int �� 1000���� ȭ�鿡 ����϶�.


void saveNum() {
	ofstream out{ "int1000��.txt", ios::out };

	for (int i = 0; i < 1000; i++) {
		out << uid(dre) << ":  ";
	}

	cout << "������ ���������� ����Ǿ����ϴ�" << endl;

	out.close();

}

int main() {
	

	srand(time(NULL)); //�ð����� �̿��ؼ� ������ ���۰��� �ٲ�
	for (int i = 0; i < 1000; i++) {
		cout<<format("{:<15}", uid(dre)); // < �������� / >���������� (�⺻) / ^ ���������
	}

	cout << "\n\n\n" << INT_MAX  << "\n" << 0B01111111'11111111'11111111'11111111 <<"\n" << 0x7FFFFFFF << endl;
	cout << numeric_limits<int>::max() << endl;
	
	saveNum();
	

}

