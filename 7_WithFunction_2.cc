// Make Function in Runtime

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

std::vector<int> ints, filtered_ints;
std::vector<std::string> strings;

int myplus(const int& a, const int& b) {
	std::cout << "[DEBUG] "<<  a << " + " << b << '\n';
	return a + b;
}
int main(void) {
	
	std::string input;
	while (std::getline(std::cin, input), input != "") {
		strings.push_back(input);
	}

	ints.resize(strings.size());

	// map (=transform)
	std::transform(
		strings.begin(),
		strings.end(),
		ints.begin(),
		[](auto& s) {
			try {
				return std::stoi(s);
			}
			catch (std::exception& e) {
				return -1;
			}
		}
	);

	for (const int& i : ints) {
		std::cout << i << '\n';
	}

	// filter
	std::copy_if(
		ints.begin(),
		ints.end(),
		std::back_inserter(filtered_ints),
		[](auto& i) {
			return i != -1;
		}
	);

	for (const int& i : filtered_ints) {
		std::cout << i << '\n';
	}

	// fold
	// foldl => ((((0 + 1) + 2) + 3) + 4)
	// foldr => (0 + (1 + (2 + (3 + 4))))
	// 하나로 줄인다

	auto foldl = std::accumulate ( // in <numeric> header
		filtered_ints.begin(),
		filtered_ints.end(),
		0,
		myplus
	);

	std::cout << "Foldl is " << foldl << '\n';

	auto foldr = std::accumulate( // in <numeric> header
		filtered_ints.rbegin(),
		filtered_ints.rend(),
		0,
		myplus
	);

	std::cout << "Foldr is " << foldr << '\n';
}