// Pure Function ���� �Լ��� ����� �Լ�
// ���� �Լ��� ������ �Է� ���� ���� ������ ���� ��ȯ�ϴ� ���̴�
// ����� �Լ��� ������ �Է� ���� ���� �������� ���� ���� ��ȯ�ϴ� ���̴� (�Է¿ܿ� �ٸ� ������ ������ �޴´�)

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