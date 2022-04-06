//-----------------------------------------------------------------------------
// STRING - STL �����Ϸ��� ���� �ڿ� ���� Ŭ����
// 
// 2022. 3. 30									Programmed by Wulong
// 
// 2022. 4. 4	                                getNum() �߰�
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>

class STRING {
	char* p;							// Ȯ���� �ڿ� �ּ�
	size_t num;							// �����ϴ� ����Ʈ ��
	int id;								// ���� �� �ο��� id
	static int gid;						// Ŭ���� ����ƽ - id ����

public:
	STRING( );
	STRING( const char* s );

	~STRING( );

	STRING( const STRING& other );
	STRING& operator=( const STRING& other );

	STRING operator+( const STRING& rhs ) const;

	void print( const char* s ) const;

	friend std::ostream& operator<<( std::ostream&, const STRING& );
	size_t getNum() const;
};
