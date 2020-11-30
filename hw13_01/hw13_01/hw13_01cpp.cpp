#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {
			if (comp(*cur, *prev)) {
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}
	}
}


struct compGreater {
	bool operator()(int arg1, int arg2) {			//인자들 중 첫번째 값이 크거나 같으면 true 리턴(내림차순 정렬용)
		return arg1 >= arg2;					
	}
};

struct compLess {
	bool operator()(int arg1, int arg2) {			//인자들 중 첫번째 값이 작으면 true 리턴(오름차순 정렬용)
		return arg1 < arg2;
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };

	std::cout << "오름차순 정렬" << std::endl;
	compLess compLess; //Functor 생성
	bubble_sort(values.begin(), values.end(), compLess);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;


	std::cout << "내림차순 정렬" << std::endl;
	compGreater compGreater; //Functor 생성
	bubble_sort(values.begin(), values.end(), compGreater);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	getchar();
}
