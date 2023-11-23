#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<unsigned> CheckRowColumn(unsigned num, unsigned y, unsigned x, vector<vector<vector<unsigned>>>& possible_nums)
	{
		vector<unsigned> temp;
		for (unsigned i = 0; i < 9; i++)
			if (possible_nums[y][i][0] == num)
				return temp;
		for (unsigned i = 0; i < 9; i++)
			if (i != y && possible_nums[i][x][0] == num)
				return temp;
		return temp;
	}
	unsigned CheckRowColumn(unsigned num, unsigned y, unsigned x, vector<vector<vector<unsigned>>>& possible_nums)
	{
		// Функция записывает для ячейки 0,0 (y,x)
		// возможные варианты убирая цифры которые повторяются
		// в строке и столбце. Добавить проверку квадрата
		for (unsigned i = 0; i < 9; i++)
			if (possible_nums[y][i][0] == num)
				return 0;
		for (unsigned i = 0; i < 9; i++)
			if (i != y && possible_nums[i][x][0] == num)
				return 0;
		return num;
	}
	void PrintSudoku(vector<vector<char>>& board)
	{
		for (unsigned i = 0; i < 9; i++)
		{
			for (unsigned j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << "\nPrintSudoku. End" << endl;
	}
	void Write_Num(vector<vector<char>>& board, unsigned x, unsigned y)
	{
		cout << endl;
		vector<char> row_nums;

		for (unsigned g = 0; g < 9; g++)
		{
			for (unsigned h = 0; h < 9; h++)
			{
				if (g == x)
				{
					cout << board[g][h] << " ";
					/*if (board[g][h] != '.')
						row_nums.push_back(board[g][h]);*/
				}
				if (h == y && g != x)
				{
					for (unsigned i = 0; i < h; cout << "  ", i++);
					cout << board[g][h];
				}
			}
			cout << endl;
		}
	}
    void solveSudoku(vector<vector<char>>& board)
	{
		const size_t main_vector = 9;
		const size_t under_vector = 9;
		for (unsigned i = 0; i < main_vector; i++)
		{
			for (unsigned j = 0; j < under_vector; j++)
			{
				if (board[i][j] == '.')
				{
					vector<unsigned> numbers_sudoku = { 1,2,3,4,5,6,7,8,9 };

				}
			}
		}
    }
};

int main()
{
	system("chcp 1251 > nul");
	Solution sl;

	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	vector<vector<vector<unsigned>>> possible_nums (9, vector<vector<unsigned>>(9, vector<unsigned>(10, 0)));

	// vector<vector>
	//     i=0
	//   j=0,1,2    
	// [ [1,2,3], [4,5,6], [7,8,9] ];
	// vector<vector<vector<int>>>
	//						g = 0
	//						j = 0
	//					   i = 0,1,2			
	// [
	//			g = 0 | j = 0 | i = 0,1,2
	//         [ [1,2,3], [4,5,6], [7,8,9] ],
	// 
	//			g = 1 | j = 0 | i = 0,1,2
	//		   [ [1,2,3], [4,5,6], [7,8,9] ],
	// 
	//			g = 2 | j = 0 | i = 0,1,2
	//		   [ [1,2,3], [4,5,6], [7,8,9] ]
	// ]
	// vec1 = all
	// vec2 = column
	// vec3 = row
	// vec[row][column][0] = исходному числу
	// { { {},{},{} }, { {},{},{} },{ {},{},{} } }
	for (int y = 0; y < 9; y++) // Столбцы
	{
		for (int x = 0; x < 9; x++) //Строки 
		{
			if (board[y][x] != '.')
				possible_nums[y][x][0] = board[y][x] - '0';
			else
				possible_nums[y][x][0] = 0;
		}
	}
	for (int y = 0; y < 9; y++) // Столбцы
	{
		for (int x = 0; x < 9; x++) //Строки 
		{
			if (possible_nums[y][x][0] != 0)
				possible_nums[y][x].resize(1);
			else
			{
				for (int z = 1; z < 10; z++) // Заполнение возможных вариантов в данной ячейке?
					possible_nums[y][x][z] = sl.CheckRowColumn(z, y, x, possible_nums); // Metod check row and column
			}
		}
	}

	// Вывод судоку
	for (int i = 0; i < 9; i++)
	{
		cout << "\t\t\tРяд в судоку: " << i + 1 << endl;
		for (int j = 0; j < 9; j++)
		{
			// Второй уровень 
			cout << " " << "Цифра в ориг: " << possible_nums[i][j][0] << " ";
			if (possible_nums[i][j].size() != 1)
			{
				cout << "\tВозможные враианты: ";
				for (int g = 1; g < 10; g++)
				{
					cout << possible_nums[i][j][g];
				}
				cout << endl;
			}
			else
				cout << endl;
		}
		cout << endl;
	}
	// Вывод судоку и возможных вариантов
	//for (int i = 0; i < 9; i++)
	//{
	//	cout << "\t\t\tРяд в судоку: " << i+1 << endl;
	//	for (int j = 0; j < 9; j++)
	//	{
	//		// Второй уровень 
	//		cout << " " << "Цифра в ориг: " << j+1 << " ";
	//		cout << "\tВозможные враианты: ";
	//		for (int g = 1; g < 10; g++)
	//		{
	//			cout << g;
	//			// Третий уровень
	//		}
	//		cout << endl;
	//	}
	//	cout << endl << endl;
	//}
	/*for (int i = 1; i < 10; i++)
	{
		cout << i;
		for (int j = 2; j < 10; j++)
		{
			cout << j;
		}
		for (int g = 1; g < 10; g++)
		{
			cout << endl;
			for (int space = 0; space < i-1; cout << " ", space++);
			cout << g;
		}
		cout << endl;
	}*/

	//sl.solveSudoku(board);
	sl.PrintSudoku(board);
	char test = ' ';
	sl.Write_Num(board, 0, 0);
	return 0;
}