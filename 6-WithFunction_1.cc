#include <functional>
#include <iostream>
#include <limits>

int add(int a, int b) {
	return a + b;
}

int div(int a, int b) {
	return a / b;
}

int mul(int a, int b) {
	return a * b;
}

int sub(int a, int b) {
	return a - b;
}
int main(void) {
	std::function<int(int, int)> functions[] = { add, sub, mul, div };

	int a, b, cmd;
	std::cin >> cmd;
	std::cin >> a >> b;

	std::cout << functions[cmd](a, b);
	
	return 0;
}