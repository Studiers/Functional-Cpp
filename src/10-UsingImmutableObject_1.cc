// �Լ��� ���α׷����� Ư¡ �� �Һ����̶�� ���� �ִ�.
// ���� ������ �����ϸ� �ȵǸ� �Լ� ����� ������ ��ġ�� �ʰ� �Լ� ������ ���� ������ ���� �ؼ��� �� �ȴ�.

#include <iostream>

auto main() -> int {
	// �Һ�, immutable ��ü�� �����
	// ���� ���� ���� ����Ǹ� �� �ȴ�.
	int immutable_1 = 1;
	int immutable_2 = immutable_1 + 1;
	int immutable_3 = immutable_2 + 1;
	int immutable_4 = immutable_3 + 1;
	int immutable_5 = immutable_4 + 1;
	int immutable_6 = immutable_5 + 1;
	int immutable_7 = immutable_6 + 1;
	int immutable_8 = immutable_7 + 1;
	int immutable_9 = immutable_8 + 1;

	// �Լ��� ���α׷����� ��Ģ�� �������� ���ɻ� ������ �ʴ�
	std::cout << immutable_9 << '\n';

	return 0;
}