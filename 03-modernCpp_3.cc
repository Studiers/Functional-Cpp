// Lambda is Art
// Lambda : [Caputre Variables](args){code}

#include <functional>
#include <iostream>

int main(void) {
	int a = 6, b = 7;
	auto f_with_ab = [a, b](int c) { return a + b + c; }; // typeid(f).name = class lambda
	
	a = 9;
	b = 0;
	
	auto f_with_all = [=](int c) { return a + b + c; }; // 람다 캡쳐는 람다 선언시 캡쳐한다
	auto f_with_ref = [&a, &b]() { a = 3, b = 5; }; // 참조를 넘기고자 한다면 앞에 &을 붙이면 된다
	
	std::cout << f_with_ab(2) << '\n' << f_with_all(2) << '\n';

	f_with_ref();

	std::cout << a << '\n' << b << '\n';

	// Initial Capture
	[&x = a]() { x += 2; }();

	std::cout << a << '\n';

	// auto를 인자에 사용하면 어떤 값이든 넣을 수 있는 제네릭 람다가 된다.
}