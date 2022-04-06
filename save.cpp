// ============================================================================
// save.cpp
// 
// ������ ������ �̸� ��ǲ - ������ ���Ͽ� �����δ�.
//    "2022 1�б� STL ��23��34 ��������.txt"
// 
// 2022. 3. 7.
// ============================================================================

#pragma once
#include <iostream>
#include <string_view>
#include <fstream>
#include <filesystem>
#include <vector>
#include <iterator>
#include <chrono>
#include <algorithm>
#include "save.h"


// �ڵ��� ���� - "�ҽ�.cpp"�� �о� ���� ���� ���Ͽ� �����δ�.


void save(std::string_view fname)
{

	
	//���� �ð��� ȭ�鿡 ����Ѵ�
	auto time = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	//cout << "\n ������� : " << chrono::zoned_time("Asia/Seoul", time) << endl;
	auto size = std::filesystem::file_size(fname);

	//������ ����
	std::ifstream in{ fname.data() };
	
	//������ ���ϵ� ����(�����̱� ���� ����� �Ѵ�
	std::ofstream out{ "2022 1�б� STL ��23��34 ��������.txt",std::ios::app };

	//������ ������ ũ��� ���� �ð��� �������� ���Ͽ� ����Ѵ�.
	out << "\n\n=============================================================================" << std::endl;
	out << "=============================================================================\n\n" << std::endl;
	out << "���� ���� : " << fname << ",  ũ�� - " << size << std::endl;
	out << "���� �ð� : " << std::chrono::zoned_time("Asia/Seoul", time) << std::endl;
	out << "\n" << std::endl;


	//cout << fname << "�� ũ�� - " << size << endl;


	// ���͸� ����鼭 in ������ ������ �� �о�´�.
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };
	//v.reserve(size);
	//v.assign();

	// v�� �о� �� ������ out�� ����Ѵ�.

	/*for (char c : v)
	{
		cout << c;
	}*/

	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{out});

}
