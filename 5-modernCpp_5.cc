// Tuple.. So beautiful

#include <iostream>
#include <tuple>

int main(void) {
	// pack
	std::tuple<int, std::string, std::string> tuple = std::make_tuple(1, "Hello World!", "Moreal");
	// or
	auto auto_tuple = std::make_tuple(1, "Hello World!", "Moreal");

	// unpack
	int index = std::get<0>(tuple);
	std::string title = std::get<1>(tuple), name = std::get<2>(tuple);
	// or
	std::tie(index, title, name) = tuple;
	// I think lower thing is better :) 
	
	return 0;
}