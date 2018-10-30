// �Լ��� ���ۿ��� IO�� �����Ѵ�.
// ���α׷� ���� ���� ��ȣ�ۿ� ���...
// Ŀ����� ���� �Լ��� �κ������� ���� ������ �ϴ� ���̴�.

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
	// volumOfRectanglular �Լ� Ŀ��
	auto length5width4 = curry(volumeOfRectanglular, 5, 4);

	for (int i(0); i < 5; ++i) {
		std::cout << length5width4(i) << '\n';
	}

	return 0;

}