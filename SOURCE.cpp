// ============================================================================
//									STL
// 
//	2022.3.2 수34              월23수34                   (1주1일)
// 
//	- 강의소개 ( 책 /  CPPReference.com /  )
//	- 코딩 스타일 ( C++ coding convention - reference(google C++ coding convention))
//	- 컴파일러 환경 세팅 ( Release mode /  X64 )
//						- 프로젝트 속성 -> 일반 -> C++ 버전 (최신 초안기능)
//	- SAVE 파일 작성
//		한학기 강의를 자동저장한다
// 
//	공부할 내용
//		- 파일 입출력 ( 텍스트 모드 / 바이너리 모드 )
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

// 코딩할 내용 - "소스.cpp"를 읽어 강의 저장 파일에 덧붙인다.

void save(string_view);

int main() 
{
//	cout << "string Size : " << sizeof(string) << endl;
//	cout << "string_view Size : " << sizeof(string_view) << endl;

	save("SOURCE.cpp");
}

void save(string_view fname) 
{

	//현재 시간을 화면에 출력한다
	auto time = floor<chrono::seconds>(chrono::system_clock::now());
	//cout << "\n 저장시점 : " << chrono::zoned_time("Asia/Seoul", time) << endl;
	auto size = filesystem::file_size(fname);

	//파일을 연다
	ifstream in { fname.data() };

	//저장한 파일도 연다(덧붙이기 모드로 열어야 한다
	ofstream out{ "2022 1학기 STL 월23수34 강의저장.txt",ios::app };
	
	//저장할 파일의 크기와 현재 시간을 강의저장 파일에 기록한다.
	out << "파일 정보 : " << fname << ",  크기 - " << size << endl;
	out << "저장 시간 : " << chrono::zoned_time("Asia/Seoul", time) << endl;
	out << endl;

	
	//cout << fname << "의 크기 - " << size << endl;


	// 벡터를 만들면서 in 파일의 내용을 다 읽어온다.
	vector<char> v{ istreambuf_iterator<char>{in}, {} };
	//v.reserve(size);
	//v.assign();


	// v로 읽어 온 파일을 out에 출력한다.

	/*for (char c : v)
	{
		cout << c;
	}*/

	copy(v.begin(), v.end(), ostream_iterator<char>{out});
	
}
