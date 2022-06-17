#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <thread>
using namespace std;


// [프로그램 환경] Release, x64, 프로젝트 속성 C++ 언어: 미리 보기 - 최신 C++ 초안의 기능(/std:c++latest)


//---------
int main()
//---------
{
	// 파일 "시험1.dat"와 "시험2.dat"에 몇 개인지 모르는 int를 저장하였다. 
	// int 값은 operator<<를 사용하여 text 모드로 기록하였다.
	// (예)	int n = 123;
	//	    out << n << " ";

	ifstream in1{ "시험1.dat" };
	ifstream in2{ "시험2.dat" };

	vector<int> v1;			// "시험1.dat"를 여기에 저장한다
	vector<int> v2;			// "시험2.dat"를 여기에 저장한다



	// [문제 1] "시험1.dat"와 "시험2.dat"를 읽어 v1과 v2에 저장하고, v1과 v2의 size()를 화면에 출력하라.
	// 답지에는 v1에 저장하는 코드만 적고 화면에 출력된 size()값을 적으면 된다.		(15, 5)
	// (주의) v1과 v2는 이미 생성되어있다.
	int tmp;
	while (in1>>tmp) {
		v1.push_back(tmp);
	}
	while (in2 >> tmp) {
		v2.push_back(tmp);
	}

	cout << v1.size() << endl;
	cout << v2.size() << endl;

	// [문제 2]	v1에 저장된 원소들을 홀수와 짝수로 분리한 후 각각 몇 개인지 출력하라.	
	// 출력한 홀수의 개수와 짝수의 개수도 답안지에 써라.							(15, 5)

	auto p = partition(v1.begin(), v1.end(), [](int i) {return i % 2 == 0;  });
	cout << distance(v1.begin(), p) << endl;
	cout << distance(p, v1.end()) << endl;
	//cout << distance(v1.begin(), p) + distance(p + 1, v1.end()) << "  " << v1.size() << endl;
	cout << *v1.begin() << " " << *p << " " << *(v1.end() - 1) << endl;

	// [문제 3] v1과 v2의 공통 원소를 찾아 v3에 저장하라.		
	// v3에 저장된 원소개수를 출력하고 답지에도 적어라.								(25, 5)
	// (참고) 공통 원소는 set_intersection으로 찾을 수 있다.
	// 같은 값을 갖는 원소가 여러 개 있을 경우는 set_intersection의 처리방법을 따른다.

	vector<int> v3;		// v1과 v2의 공통 원소를 여기에 저장한다.
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3), [](const int& a, const int& b) {
		return a < b;
		});

	cout << v3.size() << endl;

	// [문제 4] v3에 저장된 int를 화면에 출력하면 값이 나온다.
	// int 값은 [0,9] 숫자로 표현된다.
	// v3에 저장된 모든 int를 숫자로 나타낼때 각 숫자의 갯수를 화면에 출력하라.
	// '9'의 갯수는 답지에도 써라.													(35, 5)
	// (도움) to_string()으로 int를 string으로 변환할 수 있다.	
	// (예) 1231511   31233122 
	// 위 두 int에서 
	// [1] - 6
	// [2] - 4
	// [3] - 4
	// [4] - 0
	// [5] - 1
	// 이하 생략

	vector<int> v4(10);
	cout << v4.size() << endl;

	//for (int i : v3) {
	//	sTmp = to_string(i);
	//	//정렬
	//	for (const char& a : sTmp) {
	//		int i = atoi(a);
	//		//cout << i << endl;
	//	}
	//}

	for_each(v3.begin(), v3.end(), [&v4](int in) {
		while (in != 0) {
			int t = in % 10;
			v4[t]++;
			in /= 10;
		};
		});

	for (int i{}; i < 10; ++i) {
		cout << i << " : " << v4[i] << endl;
	}


	vector<int> v5(10);
	for_each(v3.begin(), v3.end(), [&v5](int n) {
		string st = to_string(n);
		sort(st.begin(), st.end());
		int i{};
		auto p = st.begin();
		p = adjacent_find(p, st.end());
		while (p != st.end()) {
			
			while (*p == *(p + 1)) {
				v5[*p]++;
				p++;
			}
			++i;
			p++;
			p = adjacent_find(p, st.end());
		}
		});

	for (int i{} ; i < 10; ++i) {
		cout << i << " : " << v5[i] << endl;
	}



}