#pragma once

template <class iter, class Call>
iter my_find(iter b, iter e, Call v) {
	while (b != e) {
		if (*b == v) {
			return b;
		}
		++b;
	}
	return e;
}

template <class iter, class Call>
iter my_find_if(iter b, iter e, Call f) {
	while (b != e) {
		if (f(*b)) {
			return b;
		}
		++b;
	}
	return e;
}

template<class source_iter, class destination_iter>
void my_copy(source_iter b, source_iter e, destination_iter d) {
	while (b != e) {
		*d = *b;
		++d; ++b;
	}
}