// 꼬리 재귀는 재귀가 끝나갈 때 자신을 다시 호출 하는 방법이다.
// 이 경우에는 컴파일러의 최적화 옵션을 통해서 최적화가 가능하다!!
// 따라서 스택 오버 플로우 등의 문제를 피할 수 있다

#include <iostream>

void displayNumber(long long n) {
	std::cout << n << '\n';

	// 함수의 끝에서 재귀 호출을 진행하였다
	// 이 경우 컴파일러는 재귀 호출을 goto문으로 치환하여 스택을 소비하지 않게 만든다
	displayNumber(n + 1);
}

auto main() -> int {
	displayNumber(0);
	return 0;
}