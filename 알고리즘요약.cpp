#include<iostream>
#include<algorithm>
#include<vector>
#include<set> // set�� ���� 1���� ����
#include<list> 

using namespace std;

void funcCall() {

	vector<int> v;
	for (int i{}; i < 100; ++i) {
		v.push_back(i);
	}
	all_of(v.begin(), v.end(), [](int i) {return i % 2 == 0; });//[bool] ��� ������ �������˻�
	//any_of : or �ϳ��� ���̾ true ����
	//none_of : ��ü�� �����̾�� Ʈ�� ����

	for_each(v.begin(), v.end(), [](int& i) {i++; }); // for���� �Լ� �ִ� ���� < for������ �ν� ���
	for_each_n(v.begin(), 3, [](int& i) {i++; }); // n��°������ �ݺ�

	count(v.begin(), v.end(), 3);
	count_if(v.begin(), v.end(), [](const int& i) {return i % 2 == 0; });








}