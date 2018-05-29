#include <iostream>

// Effective template with modern c++
// We can determine the return type in back, using auto ->
// decltype statement is to determine new type using arg
template<typename I, typename J>
auto add(I i, J j) -> decltype(i + j) {
	return i + j;
}

auto main(void) -> int {
	std::cout << add<int, double>(1, 1.5) << ' ' << typeid(add<int, double>(1, 1.5)).name(); // 2.5 double
	return 0;
}