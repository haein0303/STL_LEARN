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
	for (WP words : v 
		| views::drop(10'000)
		| views::take(50)
		) 
	{
		cout << words.first << " -- " << words.second << endl;
	}


}