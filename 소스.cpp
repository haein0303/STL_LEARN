//-----------------------------------------------------------------------------
// 2022. 3. 30 ��34							��23��34                  (4�� 2��)
// 
// �ڿ��� �����ϴ� Ŭ���� - STRING - �����̳�, �ݺ���, �˰��� 
//-----------------------------------------------------------------------------
#include <iostream>
#include <array>
#include "STRING.h"
using namespace std;

extern bool ����;

//---------
int main( )
//---------
{
	//���� = true;

	array<STRING, 3> strs { "2022�� 1�б� STL", "��23 ��34", "3�� 30�� ������ ��34���� 4�� 2�� ����"};

	for (int i = 0; i < strs.size( ); ++i)
		cout << "strs[" << i << "] - " << strs[i] << endl;

	cout << endl << endl;
	cout << "strs�� STRING 3��ü�� ��� ���� ��ü�� ����� ����" << endl << endl;

	STRING all = strs[0] + strs[1] + strs[2];
	cout << "��� ���ϸ� - " << all << endl;
}
