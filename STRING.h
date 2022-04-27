//-----------------------------------------------------------------------------
// STRING - STL 관찰하려고 만든 자원 관리 클래스
// 
// 2022. 3. 30									Programmed by Wulong
// 
// 2022. 4. 4	                                getNum() 추가
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <compare> // C++20 spaceship operator(three-way comparator)


//2022. 4. 27. STRING이 제공하는 반복자
class STRING_iterator {
	char* p;
public:
	STRING_iterator(char* p) : p{ p } {};
	operator-(const STRING_iterator& rhs) const {
		return p - rhs.p;
	}

	
};

//2022. 4. 27. STRING이 제공하는 역방향 반복자
class STRING_reverse_iterator {
private:
	char* p;
public:
	STRING_reverse_iterator(char* p) : p{ p } {};
	STRING_reverse_iterator& operator++() {
		--p;
		return *this;
	}
	char& operator*() const {
		return *(p-1);
	}
	bool operator!=(const STRING_reverse_iterator& rhs) {
		return p != rhs.p;
	}
	auto operator<=>(const STRING_reverse_iterator& rhs) const = default;
};

class STRING {
public:
	//2022. 4. 27.
	using iterator = STRING_iterator; //포장하장
	using reverse_iterator = STRING_reverse_iterator; //포장
private:
	char* p;							// 확보한 자원 주소
	size_t num;							// 관리하는 바이트 수
	int id;								// 생성 시 부여한 id
	static int gid;						// 클래스 스태틱 - id 관리

public:
	STRING( );
	STRING( const char* s );

	~STRING( );

	STRING( const STRING& other );
	STRING& operator=( const STRING& other );

	//이동생성자/ 이동할당연산자 22.04.11.
	STRING(STRING&& other) noexcept;
	STRING& operator=(STRING&& other) noexcept;


	STRING operator+( const STRING& rhs ) const;

	//22.04.27 begin()/end() 제공
	iterator begin() const {
		return iterator{ p };
	}
	iterator end() const {
		return iterator{ p + num };
	}




	reverse_iterator rbegin() const {
		return reverse_iterator{ p + num };
	}
	reverse_iterator rend() const {
		return reverse_iterator{ p };
	}

	void print( const char* s ) const;

	friend std::ostream& operator<<( std::ostream&, const STRING& );
	
	size_t getNum() const;

};


