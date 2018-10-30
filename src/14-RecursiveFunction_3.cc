// 함수형, 절차형, 백트래킹 재귀

#include <iostream>
#include <string>

// 함수형 재귀
int pow(int base, int exp) {
	if (exp == 0)
		return 1;
	else
		return base * pow(base, exp - 1);
}

// 절차형 재귀
void doPermute(
	const std::string &chosen,
	const std::string &remaining) {
	if (remaining == "") {
		std::cout << chosen << '\n';
	}
	else {
		for (uint32_t u = 0; u < remaining.length(); ++u) {
			doPermute(
				chosen + remaining[u],
				remaining.substr(0, u) + remaining.substr(u + 1)
			);
		}
	}
}

void permute(const std::string& s) {
	doPermute("", s);
}

auto main() -> int {
	permute("abcd");
	return 0;
}