// ============================================================================
//									STL
// 
//	2022.4.4. ��23              ��23��34                   
// 
// �����̳� - �ٸ���ü�� �����ϴ� ��ü
// sequence Container
//   - array    �����ϰ� ũ�Ⱑ ������ Ÿ�ӿ� ����
//   - vector   dynamic array 
// ============================================================================


#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <fstream>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

//[����] Ű���忡�� �Է��ϴ� ��� �ܾ �޾ƶ�
//������������ �����Ѵ�
//����� ����Ѵ�.

int main() {
	save("main.cpp");

	//[����] "�ҽ�.cpp"�� �о� ���ĺ��� ������ ������ ���� ����϶�
	// ��ҹ��ڴ� ���������ʴ´�.
	// [a] = 10
	// [b] = 2
	// ...
	// [z] = 1

	array<int, 26> count;

	ifstream in{ "main.cpp" };
	
	if (in) {
		cout << "file Read" << endl;

		vector<char> v{ istream_iterator<char> {in},{} };

		for (char c : v) {
			
		}
	}
	
}




