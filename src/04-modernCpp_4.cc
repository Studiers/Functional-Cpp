// Useful Smart Pointers

#include <iostream>
#include <memory>

int main(void) {
	// auto_ptr is deprecated
	// unique_ptr은 한 객체를 여러 포인터가 가리키는 것을 막는다
	// 복사 생성자와 복사 할당자를 제공하지 않는다
	// 하지만 값을 복사, 이동하는 것은 가능하다
	// auto ptr = uni_ptr; 의 경우 에러가 난다
	auto uni_ptr = std::unique_ptr<int> { new int(123) };
	int uni_val = *uni_ptr + 123;
	auto new_uni_ptr = std::make_unique<int>(uni_val);
	*new_uni_ptr += 1;
	std::cout << *uni_ptr << ' ' << uni_val << ' ' << *new_uni_ptr << '\n';

	// shared_ptr 은 포인터가 하나를 
	auto sh_ptr = std::make_shared<int>(123);
	std::cout << "sh_ptr :: " << sh_ptr.unique() << ' ' << sh_ptr.use_count() << '\n';
	auto new_sh_ptr = sh_ptr;
	std::cout << "after create new_sh_ptr :: " << sh_ptr.unique() << ' ' << sh_ptr.use_count() << '\n';
	new_sh_ptr.reset();
	std::cout << "after destroy new_sh_ptr :: " << sh_ptr.unique() << ' ' << sh_ptr.use_count() << '\n';

	// weak_ptr
	// weak_ptr은 shared_ptr의 객체를 참조하는 방식으로 운영되고 strong reference counter를 올리지 않는다
	// 그리고 실제로 접근할 방법도 없으며 접근하고자 한다면 shared_ptr로 변환, lock() method로 바꾸어 사용해야 한다.
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
	
	// 이러한 스마트 포인터는 dangling pointer의 위험성을 없애기 위함이다.

}