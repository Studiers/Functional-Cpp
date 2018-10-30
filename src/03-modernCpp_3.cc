// Lambda is Art
// Lambda : [Caputre Variables](args){code}

#include <functional>
#include <iostream>

int main(void) {
	int a = 6, b = 7;
	auto f_with_ab = [a, b](int c) { return a + b + c; }; // typeid(f).name = class lambda
	
	a = 9;
	b = 0;
	
	auto f_with_all = [=](int c) { return a + b + c; }; // ���� ĸ�Ĵ� ���� ����� ĸ���Ѵ�
	auto f_with_ref = [&a, &b]() { a = 3, b = 5; }; // ������ �ѱ���� �Ѵٸ� �տ� &�� ���̸� �ȴ�
	
	std::cout << f_with_ab(2) << '\n' << f_with_all(2) << '\n';

	f_with_ref();

	std::cout << a << '\n' << b << '\n';

	// Initial Capture
	[&x = a]() { x += 2; }();

	std::cout << a << '\n';

	// auto�� ���ڿ� ����ϸ� � ���̵� ���� �� �ִ� ���׸� ���ٰ� �ȴ�.
}