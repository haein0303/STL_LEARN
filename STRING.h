//-----------------------------------------------------------------------------
// STRING - STL �����Ϸ��� ���� �ڿ� ���� Ŭ����
// 
// 2022. 3. 30									Programmed by Wulong
// 
// 2022. 4. 4	                                getNum() �߰�
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <compare> // C++20 spaceship operator(three-way comparator)


//2022. 4. 27. STRING�� �����ϴ� �ݺ���
class STRING_iterator {
public:
	//2022. 5. 2. ��� ǥ�� �����̳ʴ� �Ʒ� 5���� ����
	using iterator_category = std::random_access_iterator_tag;
	using value_type = char;
	using difference_type = ptrdiff_t;
	using pointer = const char*;
	using reference = const char&;

private:
	char* p;
public:
	STRING_iterator(char* p) : p{ p } {};
	
	//2022.5.2. sort�� �ʿ��� �����ڵ� ����
	difference_type operator-(const STRING_iterator& rhs) const {
		return p - rhs.p;
	}

	auto operator<=>(const STRING_iterator&) const = default;

	STRING_iterator& operator++() {
		 ++p;
		 return *this;
	}

	STRING_iterator& operator--() {
		--p;
		return *this;
	}

	char& operator*() const {
		return *p;
	}
	
	STRING_iterator operator+(difference_type rhs) const {
		return STRING_iterator{ p + rhs };
	}	

	STRING_iterator operator-(difference_type rhs) const {
		return STRING_iterator{ p - rhs };
	}

};

//2022. 4. 27. STRING�� �����ϴ� ������ �ݺ���
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
	using iterator = STRING_iterator; //��������
	using reverse_iterator = STRING_reverse_iterator; //����
private:
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

	//�̵�������/ �̵��Ҵ翬���� 22.04.11.
	STRING(STRING&& other) noexcept;
	STRING& operator=(STRING&& other) noexcept;


	STRING operator+( const STRING& rhs ) const;
	//22.05.02 default< ������
	bool operator<(const STRING& rhs) const {
		return num < rhs.num;
	}

	//22.05.18 unordered_set�� �䱸�ϴ� ==
	/*bool operator== (const STRING& rhs)const {
		return std::string(begin(), end()) == std::string(rhs.begin(), rhs.end());
	}*/

	//22.04.27 begin()/end() ����
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
	friend std::istream& operator>>(std::istream&, const STRING&);
	size_t getNum() const;


	
};

//bool operator< (const STRING& lhs, const STRING& rhs) {
//	//�����ĺ� �˰���
//	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
//	//return string(lhs.begin(),lhs.end()) < string(rhs.begin(),rhs.end());
//}


