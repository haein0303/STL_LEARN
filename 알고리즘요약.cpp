#include<iostream>
#include<algorithm>
#include<vector>
#include<set> // set은 정렬 1개만 저장
#include<list> 

using namespace std;

void funcCall() {

	vector<int> v;
	for (int i{}; i < 100; ++i) {
		v.push_back(i);
	}
	all_of(v.begin(), v.end(), [](int i) {return i % 2 == 0; });//[bool] 모든 조건이 참인지검사
	//any_of : or 하나만 참이어도 true 리턴
	//none_of : 전체가 거짓이어야 트루 리턴

	for_each(v.begin(), v.end(), [](int& i) {i++; }); // for문에 함수 넣는 느낌 < for문보다 훨신 우월
	for_each_n(v.begin(), 3, [](int& i) {i++; }); // n번째까지만 반복

	count(v.begin(), v.end(), 3);
	count_if(v.begin(), v.end(), [](const int& i) {return i % 2 == 0; });








}