// ============================================================================
//									STL
// 
//	2022.6.6.        ��34              ��23��34               13�� 2��     
//
//	�˰��� - ��͵��� �ֳ� ���캻��
// 
// 
// ============================================================================


#include <iostream>
#include <concepts>
#include <string>
#include <format>
#include <vector>
#include <ranges>
#include <algorithm>
#include <fstream>
#include <set>
#include <list>
#include "save.h"
#include "STRING.h"
#include "my_Algorithm.h"
 
using namespace std;

struct WP : pair<string,string> { //wordPair
	WP(string s) : pair<string, string>{ s,s } {
		sort(first.begin(), first.end());
	};


};



int main() {

	save("main.cpp");

	ifstream in{ "�ܾ��.txt" };
	vector<WP> v(istream_iterator<string>{ in }, {}); //�ܾ� �� 369882
	
	ranges::sort(v, {}, &WP::first);

	//[����] �Է��� �ܾ ������ �ִٸ�
	// anagram ���迡 �ִ� �ܾ ��� ����϶�
	
	//�Է��� �ܾ ������ �ִ��� Ȯ��
		//�ִ� �ܾ���?
		//�ܾ ���� / ������ �ܾ�� wp�� first�� ��ġ�ϴ� �ܾ���� ��� ã�´�
		//���� second ���


	//[����] ��ü anagram ���� ����϶�.
	//���� WP�� ���� WP���� first�� ����? - adjacent_find()
	//���� ��ġ�� �߰��ߴٸ�
	// �޶����� ���� ����?

	//[����] ��ü anagram ���� ���� ���� ������������ ����϶�

	vector<WP>::iterator i = v.begin();
	int cnt{};
//	ofstream out{ "���ʱ׷�.txt" };

	set<pair<int, vector<string>>> s;

	vector<list<string>> vls;
	
	while (true) {
		
		i = adjacent_find(i, v.end(), [](const WP& a, const WP& b) {
			return a.first == b.first;
			});

		if (i == v.end()) {
			break;
		}
		auto j = find_if_not(i + 1, v.end(), [i](const WP& a) {
			return a.first == i->first;
			});

		//[i,j) ������ ���� anagram �����̴�

		list<string> ls;

		for (auto p = i; p < j; ++p) {
			ls.push_back(p->second);
		}
		vls.push_back(ls);

		i = j;
	}
	
	sort(vls.begin(), vls.end(), [](const list<string>& a, const list<string>& b) {
		return a.begin()->size() > b.begin()->size();
		});

	//cout << "���� ������ ���� �� - " << vls[0].size() << endl;
	for (const list<string>& ls : vls | views::take(1000)) {
		for (const string& s : ls ) {
			cout << s << " ";
		}
		cout << endl;
	}

}