#include <vector>

using std::vector;

// 백트래킹 재귀
// 길찾기 등에서 사용하는 방식이다
bool navigate(
	vector<vector<char>> labyrinth,
	int row,
	int col) 
{
	if (labyrinth[row][col] == 'F') {
		return true;
	}
	else if (
		labyrinth[row][col] == '#' ||
		labyrinth[row][col] == '*') {
		return false;
	}
	else if (labyrinth[row][col] == ' ') {
		labyrinth[row][col] = '*';
	}

	// navigate recursive
	if (row + 1 < labyrinth.size() && navigate(labyrinth, row + 1, col))
		return true;
	
	if (row - 1 > 0 && navigate(labyrinth, row - 1, col))
		return true;

	if (col + 1 < labyrinth[0].size() && navigate(labyrinth, row, col + 1))
		return true;

	if (col - 1 > 0 && navigate(labyrinth, row, col - 1))
		return true;
	
	return false;
}

auto main() -> int {
	return 0;
}