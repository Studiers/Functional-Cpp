// Useful Smart Pointers

#include <iostream>
#include <memory>

int main(void) {
	// auto_ptr is deprecated
	// unique_ptr�� �� ��ü�� ���� �����Ͱ� ����Ű�� ���� ���´�
	// ���� �����ڿ� ���� �Ҵ��ڸ� �������� �ʴ´�
	// ������ ���� ����, �̵��ϴ� ���� �����ϴ�
	// auto ptr = uni_ptr; �� ��� ������ ����
	auto uni_ptr = std::unique_ptr<int> { new int(123) };
	int uni_val = *uni_ptr + 123;
	auto new_uni_ptr = std::make_unique<int>(uni_val);
	*new_uni_ptr += 1;
	std::cout << *uni_ptr << ' ' << uni_val << ' ' << *new_uni_ptr << '\n';

	// shared_ptr �� �����Ͱ� �ϳ��� 
	auto sh_ptr = std::make_shared<int>(123);
	std::cout << "sh_ptr :: " << sh_ptr.unique() << ' ' << sh_ptr.use_count() << '\n';
	auto new_sh_ptr = sh_ptr;
	std::cout << "after create new_sh_ptr :: " << sh_ptr.unique() << ' ' << sh_ptr.use_count() << '\n';
	new_sh_ptr.reset();
	std::cout << "after destroy new_sh_ptr :: " << sh_ptr.unique() << ' ' << sh_ptr.use_count() << '\n';

	// weak_ptr
	// weak_ptr�� shared_ptr�� ��ü�� �����ϴ� ������� ��ǰ� strong reference counter�� �ø��� �ʴ´�
	// �׸��� ������ ������ ����� ������ �����ϰ��� �Ѵٸ� shared_ptr�� ��ȯ, lock() method�� �ٲپ� ����ؾ� �Ѵ�.
	auto wk_ptr = std::weak_ptr<int>{ sh_ptr };
	auto tmp_ptr = wk_ptr.lock();
	if (tmp_ptr) {
		std::cout << "This is alive\n";
	}

	tmp_ptr.reset();
	sh_ptr.reset();

	tmp_ptr = wk_ptr.lock();
	if (tmp_ptr) {
		// This code will not execute
		std::cout << "This is alive after reset sh_ptr\n";
	}
	
	// �̷��� ����Ʈ �����ʹ� dangling pointer�� ���輺�� ���ֱ� �����̴�.

}