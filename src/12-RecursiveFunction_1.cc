// ����Լ��� �Լ� A�� �ٽ� �ڽ��� ȣ���ϴ� �����̴�
// ����Լ��� �Լ��� ���¸� �ٲ� �ʿ� ���� ������ �ð�ȭ��, ���� �ذ��� �����ϰ� ����� ���� ���� ���� ������ ��ģ��

// �ݺ����� "��Ǯ�� �ϸ� �����Ѵ�"�� ������ ������
// ����Լ��� �۾��� �ذ��ϱ� ���� ��Ǯ�� �ϸ� ��� ���� ������� ������ ���̴�

// ������ ����Լ��� �Լ��� ���°� �ٲ� �ʿ䰡 ���� �Լ��� ���α׷��ֿ� ���� �� ��︰��!!

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