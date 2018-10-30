#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int main(void) {
	
	std::vector<int> vec;

	std::default_random_engine gen;
	std::uniform_int_distribution<int> distribution(1, 100);

	for (int i(0); i < 100; ++i) {
		vec.push_back(distribution(gen));
	}
	
	std::sort(vec.begin(), vec.end(), [](const int& i, const int& j) { return i < j; });

	std::for_each(
		vec.begin(),
		vec.end(),
		[](const auto& e) {
			std::cout << e << '\n';
		}
	);

	return 0;
}