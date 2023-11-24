#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
	
	// Вывод конкретной строки и столбца
	void Write_Num(vector<vector<char>>& board, unsigned y, unsigned x)
	{
		cout << endl;
		vector<char> row_nums;

		for (unsigned g = 0; g < 9; g++)
		{
			for (unsigned h = 0; h < 9; h++)
			{
				if (g == y)
				{
					cout << board[g][h] << " ";
					/*if (board[g][h] != '.')
						row_nums.push_back(board[g][h]);*/
				}
				if (h == x && g != y)
				{
					for (unsigned i = 0; i < h; cout << "  ", i++);
					cout << board[g][h];
				}
			}
			cout << endl;
		}
	}
	
	// Заполнение уникальными значениями
	vector<unsigned> Set_Uniq(vector<vector<vector<unsigned>>>& possible_nums, unsigned y, unsigned x)
	{
		// Add all nums
		vector<unsigned> all_nums;
		for (int i = 0; i < 9; i++)
			if (possible_nums[y][i][0] != 0) all_nums.push_back(possible_nums[y][i][0]);
		for (int j = 0; j < 9; j++)
			if (possible_nums[j][x][0] != 0) all_nums.push_back(possible_nums[j][x][0]);
		
		// Если есть совпадают цифры значит не добавляем
		vector<unsigned> Uniq_num;
		Uniq_num.push_back(0);
		for (int i = 1; i < 10; i++)
			if (!count(all_nums.begin(), all_nums.end(), i))
				Uniq_num.push_back(i);
		return Uniq_num;
	}

	// Преобразование set to vec
	vector<unsigned> to_vec(set<unsigned> Uniq_num)
	{
		vector<unsigned> result;
		result.push_back(0); // Значение в судоку. Дальше заполнение возможных вариантов
		for (unsigned n : Uniq_num)
			result.push_back(n);
		return result;
	}

	// Инвертировать текущие значения в обратные
	vector<unsigned> reverse_num(vector<unsigned> Uniq_num)
	{
		vector<unsigned> reverse_vec;



		return reverse_vec;
	}

	// Функция перевода в int всю доску и заполнение возможными вариантами.
	vector<vector<vector<unsigned>>> Write_Unsigned_board(vector<vector<vector<unsigned>>>& possible_nums, vector<vector<char>>& board)
	{
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
					possible_nums[y][x] = Set_Uniq(possible_nums, y, x);
			}
		}
		return possible_nums;
	}

	// Unused func
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

	// Вывод всей строки и информации к ней
	void CoutSudokuAndVar(vector<vector<vector<unsigned>>>& possible_nums)
	{
		for (int i = 0; i < 9; i++)
		{
			cout << "\t\t\tРяд в судоку: " << i + 1 << endl;
			for (int j = 0; j < 9; j++)
			{
				// Второй уровень 
				cout << j+1 << "-Цифра в ориг: " << possible_nums[i][j][0] << " ";
				if (possible_nums[i][j].size() != 1)
				{
					cout << "\tВозможные враианты: ";
					for (int g = 1; g < possible_nums[i][j].size(); g++)
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
	}

	// Вывод всей доски
	void PrintBoardSudoku(vector<vector<char>>& board)
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

	possible_nums = sl.Write_Unsigned_board(possible_nums, board);

	
	
	sl.CoutSudokuAndVar(possible_nums);
	cout << "Set" << endl;
	for (unsigned n : sl.Set_Uniq(possible_nums, 0, 6)) // Функция для сбора уникальных значений с строчек и столбцов
		cout << n << ' ';
	cout << endl;
	
	//sl.PrintBoardSudoku(board); // Print all board
	//sl.Write_Num(board, 0, 6); // Функция для вывода необхождимых строчек и стоблцов
	return 0;
}

















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