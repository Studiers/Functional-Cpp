// 함수형 프로그래밍의 특징 중 불변성이라는 것이 있다.
// 지역 변수를 수정하면 안되며 함수 결과에 영향을 미치지 않게 함수 내에서 전역 변수에 접근 해서는 안 된다.

#include <iostream>

auto main() -> int {
	// 불변, immutable 객체를 만든다
	// 선언 이후 값이 변경되면 안 된다.
	int immutable_1 = 1;
	int immutable_2 = immutable_1 + 1;
	int immutable_3 = immutable_2 + 1;
	int immutable_4 = immutable_3 + 1;
	int immutable_5 = immutable_4 + 1;
	int immutable_6 = immutable_5 + 1;
	int immutable_7 = immutable_6 + 1;
	int immutable_8 = immutable_7 + 1;
	int immutable_9 = immutable_8 + 1;

	// 함수형 프로그래밍의 규칙을 지켰지만 성능상 좋지는 않다
	std::cout << immutable_9 << '\n';

	return 0;
}