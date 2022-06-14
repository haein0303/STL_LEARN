


#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ranges>
using namespace std;

class Test {
public:
	string name;
	int id;
public:
	void write(ostream& os) {
		os.write((char*)this, sizeof(Test));
	}

	void show() const {
		cout << name << "," << id << endl;
	}
};


int main() {

	ifstream in1{ "1.dat",ios::binary };
	ifstream in2{ "2.dat",ios::binary };

	if (!in1 or !in2) {
		cout << "파일을 열 수 없습니다" << endl;
		return 0;
	}

	vector<Test> v1, v2;
	Test tmp;
	while (in1.read((char*)&tmp, sizeof(Test))) {
		v1.push_back(tmp);
	}
	cout << v1.size() << endl;

	while (in2.read((char*)&tmp, sizeof(Test))) {
		v2.push_back(tmp);
	}
	cout << v2.size() << endl;

	sort(v1.begin(), v1.end(), [](const Test& a, const Test& b) {
		return a.name < b.name;
		});
	sort(v2.begin(), v2.end(), [](const Test& a, const Test& b) {
		return a.name < b.name;
		});

	vector<Test> v3;

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3), [](const Test& a, const Test& b) {
		return a.name < b.name;
		});

	cout << v3.size() << endl;

	auto addOne = [](vector<Test>::iterator a) {
		return a;
	};

	for (auto tmp : v3 | views::take(10)) {
		cout << tmp.id << " : " << tmp.name << endl;
	}

	copy(v3.begin(), v3.end(), addOne(v3.begin()));
	cout << "=====================" << endl;
	for (auto tmp : v3 | views::take(10000)) {
		cout << tmp.id << " : " << tmp.name << endl;
	}



	for (char i = 'a'; i <= 'z'; ++i) {
		Test tmp{};
		tmp.name = i;
		auto p = equal_range(v1.begin(), v1.end(), tmp, [](const Test& a, const Test& b) {
			return a.name[0] < b.name[0];
			});
		cout << i << " : " << distance(p.first, p.second) << endl;
	}

	for (char i = 'a'; i <= 'z'; ++i) {
		int counter{};
		for (auto p : v1) {
			if (p.name[0] == i) {
				counter++;
			}
		}
		cout << (char)i << " : " << counter << endl;
	}


}

