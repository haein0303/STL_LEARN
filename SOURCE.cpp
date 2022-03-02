// ============================================================================
//									STL
// 
//	2022.3.2 ��34              ��23��34                   (1��1��)
// 
//	- ���ǼҰ� ( å /  CPPReference.com /  )
//	- �ڵ� ��Ÿ�� ( C++ coding convention - reference(google C++ coding convention))
//	- �����Ϸ� ȯ�� ���� ( Release mode /  X64 )
//						- ������Ʈ �Ӽ� -> �Ϲ� -> C++ ���� (�ֽ� �ʾȱ��)
//	- SAVE ���� �ۼ�
//		���б� ���Ǹ� �ڵ������Ѵ�
// 
//	������ ����
//		- ���� ����� ( �ؽ�Ʈ ��� / ���̳ʸ� ��� )
//		-
// 
// ============================================================================

#include <iostream>
#include <string_view>
#include <fstream>
#include <filesystem>
#include <vector>
#include <iterator>
#include <chrono>
#include <algorithm>

using namespace std;

// �ڵ��� ���� - "�ҽ�.cpp"�� �о� ���� ���� ���Ͽ� �����δ�.

void save(string_view);

int main() 
{
//	cout << "string Size : " << sizeof(string) << endl;
//	cout << "string_view Size : " << sizeof(string_view) << endl;

	save("SOURCE.cpp");
}

void save(string_view fname) 
{

	//���� �ð��� ȭ�鿡 ����Ѵ�
	auto time = floor<chrono::seconds>(chrono::system_clock::now());
	//cout << "\n ������� : " << chrono::zoned_time("Asia/Seoul", time) << endl;
	auto size = filesystem::file_size(fname);

	//������ ����
	ifstream in { fname.data() };

	//������ ���ϵ� ����(�����̱� ���� ����� �Ѵ�
	ofstream out{ "2022 1�б� STL ��23��34 ��������.txt",ios::app };
	
	//������ ������ ũ��� ���� �ð��� �������� ���Ͽ� ����Ѵ�.
	out << "���� ���� : " << fname << ",  ũ�� - " << size << endl;
	out << "���� �ð� : " << chrono::zoned_time("Asia/Seoul", time) << endl;
	out << endl;

	
	//cout << fname << "�� ũ�� - " << size << endl;


	// ���͸� ����鼭 in ������ ������ �� �о�´�.
	vector<char> v{ istreambuf_iterator<char>{in}, {} };
	//v.reserve(size);
	//v.assign();


	// v�� �о� �� ������ out�� ����Ѵ�.

	/*for (char c : v)
	{
		cout << c;
	}*/

	copy(v.begin(), v.end(), ostream_iterator<char>{out});
	
}
