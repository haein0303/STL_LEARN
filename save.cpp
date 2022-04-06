// ============================================================================
// save.cpp
// 
// 저장할 파일의 이름 인풋 - 지정된 파일에 덧붙인다.
//    "2022 1학기 STL 월23수34 강의저장.txt"
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


// 코딩할 내용 - "소스.cpp"를 읽어 강의 저장 파일에 덧붙인다.


void save(std::string_view fname)
{

	
	//현재 시간을 화면에 출력한다
	auto time = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	//cout << "\n 저장시점 : " << chrono::zoned_time("Asia/Seoul", time) << endl;
	auto size = std::filesystem::file_size(fname);

	//파일을 연다
	std::ifstream in{ fname.data() };
	
	//저장한 파일도 연다(덧붙이기 모드로 열어야 한다
	std::ofstream out{ "2022 1학기 STL 월23수34 강의저장.txt",std::ios::app };

	//저장할 파일의 크기와 현재 시간을 강의저장 파일에 기록한다.
	out << "\n\n=============================================================================" << std::endl;
	out << "=============================================================================\n\n" << std::endl;
	out << "파일 정보 : " << fname << ",  크기 - " << size << std::endl;
	out << "저장 시간 : " << std::chrono::zoned_time("Asia/Seoul", time) << std::endl;
	out << "\n" << std::endl;


	//cout << fname << "의 크기 - " << size << endl;


	// 벡터를 만들면서 in 파일의 내용을 다 읽어온다.
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };
	//v.reserve(size);
	//v.assign();

	// v로 읽어 온 파일을 out에 출력한다.

	/*for (char c : v)
	{
		cout << c;
	}*/

	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{out});

}
