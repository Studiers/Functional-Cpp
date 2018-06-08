// 재귀함수는 함수 A가 다시 자신을 호출하는 형식이다
// 재귀함수는 함수의 형태를 바꿀 필요 없기 때문에 시각화나, 문제 해결을 간단하게 만드는 곳에 대해 좋은 영향을 미친다

// 반복문은 "되풀이 하며 유지한다"에 중점이 있지만
// 재귀함수는 작업을 해결하기 위해 되풀이 하며 계속 작은 조각들로 나누는 것이다

// 더욱이 재귀함수는 함수의 형태가 바뀔 필요가 없어 함수형 프로그래밍에 정말 잘 어울린다!!

#include <iostream>

int factorialWithRepeat(int n) {
	int result = 1, i = 1;

	do {
		result *= i;
	} while (++i <= n);

	return result;
}

int factorialWithRecursive(int n) {
	if (n == 1)
		return 1;

	return n * factorialWithRecursive(n - 1);
}
auto main() -> int {
	const int n = 11;

	std::cout << factorialWithRepeat(n) << '\n';
	std::cout << factorialWithRecursive(n) << '\n';

	return 0;
}