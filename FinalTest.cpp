#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <thread>
using namespace std;


// [���α׷� ȯ��] Release, x64, ������Ʈ �Ӽ� C++ ���: �̸� ���� - �ֽ� C++ �ʾ��� ���(/std:c++latest)


//---------
int main()
//---------
{
	// ���� "����1.dat"�� "����2.dat"�� �� ������ �𸣴� int�� �����Ͽ���. 
	// int ���� operator<<�� ����Ͽ� text ���� ����Ͽ���.
	// (��)	int n = 123;
	//	    out << n << " ";

	ifstream in1{ "����1.dat" };
	ifstream in2{ "����2.dat" };

	vector<int> v1;			// "����1.dat"�� ���⿡ �����Ѵ�
	vector<int> v2;			// "����2.dat"�� ���⿡ �����Ѵ�



	// [���� 1] "����1.dat"�� "����2.dat"�� �о� v1�� v2�� �����ϰ�, v1�� v2�� size()�� ȭ�鿡 ����϶�.
	// �������� v1�� �����ϴ� �ڵ常 ���� ȭ�鿡 ��µ� size()���� ������ �ȴ�.		(15, 5)
	// (����) v1�� v2�� �̹� �����Ǿ��ִ�.
	int tmp;
	while (in1>>tmp) {
		v1.push_back(tmp);
	}
	while (in2 >> tmp) {
		v2.push_back(tmp);
	}

	cout << v1.size() << endl;
	cout << v2.size() << endl;

	// [���� 2]	v1�� ����� ���ҵ��� Ȧ���� ¦���� �и��� �� ���� �� ������ ����϶�.	
	// ����� Ȧ���� ������ ¦���� ������ ������� ���.							(15, 5)

	auto p = partition(v1.begin(), v1.end(), [](int i) {return i % 2 == 0;  });
	cout << distance(v1.begin(), p) << endl;
	cout << distance(p, v1.end()) << endl;
	//cout << distance(v1.begin(), p) + distance(p + 1, v1.end()) << "  " << v1.size() << endl;
	cout << *v1.begin() << " " << *p << " " << *(v1.end() - 1) << endl;

	// [���� 3] v1�� v2�� ���� ���Ҹ� ã�� v3�� �����϶�.		
	// v3�� ����� ���Ұ����� ����ϰ� �������� �����.								(25, 5)
	// (����) ���� ���Ҵ� set_intersection���� ã�� �� �ִ�.
	// ���� ���� ���� ���Ұ� ���� �� ���� ���� set_intersection�� ó������� ������.

	vector<int> v3;		// v1�� v2�� ���� ���Ҹ� ���⿡ �����Ѵ�.
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3), [](const int& a, const int& b) {
		return a < b;
		});

	cout << v3.size() << endl;

	// [���� 4] v3�� ����� int�� ȭ�鿡 ����ϸ� ���� ���´�.
	// int ���� [0,9] ���ڷ� ǥ���ȴ�.
	// v3�� ����� ��� int�� ���ڷ� ��Ÿ���� �� ������ ������ ȭ�鿡 ����϶�.
	// '9'�� ������ �������� ���.													(35, 5)
	// (����) to_string()���� int�� string���� ��ȯ�� �� �ִ�.	
	// (��) 1231511   31233122 
	// �� �� int���� 
	// [1] - 6
	// [2] - 4
	// [3] - 4
	// [4] - 0
	// [5] - 1
	// ���� ����

	vector<int> v4(10);
	cout << v4.size() << endl;

	//for (int i : v3) {
	//	sTmp = to_string(i);
	//	//����
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