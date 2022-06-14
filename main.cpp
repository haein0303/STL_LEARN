// ============================================================================
//									STL
// 
//	2022.6.6.        수34              월23수34               13주 2일     
//
//	알고리즘 - 어떤것들이 있나 살펴본다
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

	ifstream in{ "단어들.txt" };
	vector<WP> v(istream_iterator<string>{ in }, {}); //단어 수 369882
	
	ranges::sort(v, {}, &WP::first);

	//[문제] 입력한 단어가 사전에 있다면
	// anagram 관계에 있는 단어를 모두 출력하라
	
	//입력한 단어가 사전에 있는지 확인
		//있는 단어라면?
		//단어를 정렬 / 정렬한 단어와 wp의 first와 일치하는 단어쌍을 모두 찾는다
		//이후 second 출력


	//[문제] 전체 anagram 쌍을 출력하라.
	//현재 WP와 다음 WP에서 first가 같니? - adjacent_find()
	//같은 위치를 발견했다면
	// 달라지는 곳은 어디니?

	//[문제] 전체 anagram 쌍을 개수 기준 내림차순으로 출력하라

	vector<WP>::iterator i = v.begin();
	int cnt{};
//	ofstream out{ "에너그램.txt" };

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

		//[i,j) 구간은 서로 anagram 관계이다

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

	//cout << "가장 개수가 많은 쌍 - " << vls[0].size() << endl;
	for (const list<string>& ls : vls | views::take(1000)) {
		for (const string& s : ls ) {
			cout << s << " ";
		}
		cout << endl;
	}

}