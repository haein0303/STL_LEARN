#include "playground.h"
#include <iostream>

void change(auto& a, auto& b) {
	auto tmp{ b };
	b = a;
	a = tmp;
}
