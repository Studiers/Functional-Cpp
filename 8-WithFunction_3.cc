// Pure Function 순수 함수와 비순수 함수
// 순수 함수는 일정한 입력 값에 대해 일정한 값을 반환하는 것이다
// 비순수 함수는 일정한 입력 값에 대해 일정하지 않은 값을 반환하는 것이다 (입력외에 다른 변수의 영향을 받는다)

#include <iostream>

int otherVal = 1;

int fureFunction(int a, int b) {
	return a + b;
}

int notFureFunction(int a, int b) {
	return (a + b) * otherVal++;
}

auto main() -> int {
	std::cout << "Result of fureFunction(1, 2);\n";
	for (int i(0); i < 5; ++i) {
		std::cout << fureFunction(1, 2) << '\n';
	}

	std::cout << "Result of notFureFunction(1, 2);\n";
	for (int i(0); i < 5; ++i) {
		std::cout << notFureFunction(1, 2) << '\n';
	}
}