#include <iostream>

using namespace std;

bool grid[8][8];

void place_queen(int x, int y)
{
	grid[y][x] = true;
}

void remove_queen(int x, int y)
{
	grid[y][x] = false;
}

void print_grid()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			cout << grid[y][x] << " ";
		}
		
		cout << "\n";
	}
}

bool is_safe(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		if (grid[y][i] == true) return false;
		if (grid[i][x] == true) return false;
	}
	
	for (int i = x, j = y; i >= 0 and j >= 0; i--, j--)
	{
		if (grid[j][i] == true) return false;
	}
	
	for (int i = x, j = y; i >= 0 and j < 8; i--, j++)
	{
		if (grid[j][i] == true) return false;
	}
	
	return true;
}

bool solve(int x)
{
	if (x >= 8) return true;
	
	for (int y = 0; y < 8; y++)
	{
		if (is_safe(x, y))
		{
			place_queen(x, y);
			if (solve(x + 1)) return true;
			remove_queen(x, y);
		}
	}
	
	return false;
}

int main()
{
	solve(0);
	
	print_grid();
	return 0;
}
