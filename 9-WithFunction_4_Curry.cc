// 함수의 부작용은 IO를 포함한다.
// 프로그램 영역 밖의 상호작용 등등...
// 커리라는 것은 함수를 부분적으로 실행 가능케 하는 것이다.

#include <iostream>
#include <functional>

template<typename Func, typename... Args>
auto curry(Func func, Args... args) {
	return [=](auto... lastParams) {
		return func(args..., lastParams...);
	};
}

int areaOfRectangle(int length, int width) {
	return length * width;
}

int volumeOfRectanglular(
	int height,
	int width,
	int length)
{
	return length * width * height;
}

auto main() -> int {
	// volumOfRectanglular 함수 커링
	auto length5width4 = curry(volumeOfRectanglular, 5, 4);

	for (int i(0); i < 5; ++i) {
		std::cout << length5width4(i) << '\n';
	}

	return 0;

}