#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
	// Once at the beginning of the work, fill in the vector
	vector<vector<vector<unsigned>>> First_fill(vector<vector<vector<unsigned>>>& possible_nums, vector<vector<char>>& board)
	{
		for (int y = 0; y < 9; y++) // Columns
		{
			for (int x = 0; x < 9; x++) // Rows 
			{
				if (board[y][x] != '.')
					possible_nums[y][x][0] = board[y][x] - '0';
				else
					possible_nums[y][x][0] = 0;
			}
		}
		return possible_nums;
	}
	
	// Filling in with unique values
	vector<unsigned> Set_Uniq(vector<vector<vector<unsigned>>>& possible_nums, unsigned y, unsigned x)
	{
		// Add all nums
		vector<unsigned> all_nums;
		for (int i = 0; i < 9; i++)
			if (possible_nums[y][i][0] != 0) all_nums.push_back(possible_nums[y][i][0]);
		for (int j = 0; j < 9; j++)
			if (possible_nums[j][x][0] != 0) all_nums.push_back(possible_nums[j][x][0]);
		
		// Check square
		vector<unsigned> square = What_square(y, x);

		vector<unsigned> Uniq_num;
		Uniq_num.push_back(0);
		for (int i = 1; i < 10; i++)
			if (!count(all_nums.begin(), all_nums.end(), i) && !count(square.begin(), square.end(), i))
				Uniq_num.push_back(i);
		/*
		We check the possible values by storing all the numbers.
		If the number is not in the vector of rows and columns (all_nums),
		and also in the vector of the square, then we add it to the vector 
		and assign it the index that we worked with earlier
		*/
		return Uniq_num;
	}

	// For work
	vector<vector<vector<unsigned>>> Check(vector<vector<vector<unsigned>>>& possible_nums)
	{
		for (int y = 0; y < 9; y++) // Column	
		{
			for (int x = 0; x < 9; x++) // Rows 
			{
				if (possible_nums[y][x].size() == 2 && possible_nums[y][x][0] == 0)
					possible_nums[y][x][0] = possible_nums[y][x][1]; // Write one possible num
				if (possible_nums[y][x][0] != 0)
					possible_nums[y][x].resize(1);
				else
					possible_nums[y][x] = Set_Uniq(possible_nums, y, x);
			}
		}
		return possible_nums;
	}

	// In this function, we determine the index of the square
	// from which we need to take values in the Fill_Square function.
	vector<unsigned> What_square(unsigned y, unsigned x)
	{
		
		// return {start y, start x} 
		if (0 <= y && y <= 2)
		{
			if (0 <= x && x <= 2)
				return { 0, 0 };
			else if (3 <= x && x <= 5)
				return { 0, 3 };
			else
				return { 0, 6 };
		}
		else if (3 <= y && y <= 5)
		{
			if (0 <= x && x <= 2)
				return { 3, 0 };
			else if (3 <= x && x <= 5)
				return { 3, 3 };
			else
				return { 3, 6 };
		}
		else
		{
			if (0 <= x && x <= 2)
				return { 6, 0 };
			else if (3 <= x && x <= 5)
				return { 6, 3 };
			else
				return { 6, 6 };
		}
	}

	// filling the vector with values from the square
	vector<unsigned> Fill_Square(unsigned y_start, unsigned x_start, vector<vector<vector<unsigned>>>& possible_nums)
	{
		vector<unsigned> out_Square;
		for (unsigned temp_y = y_start; temp_y < (y_start + 3); temp_y++)
		{
			for (unsigned temp_x = x_start; temp_x < (x_start + 3); temp_x++)
				if (possible_nums[temp_y][temp_x][0] != 0)
					out_Square.push_back(possible_nums[temp_y][temp_x][0]);
		}
		return out_Square;
	}




	// Debug part

	// Output of a specific row and column
	void Write_Num(vector<vector<char>>& board, unsigned y, unsigned x)
	{
		cout << endl;
		vector<char> row_nums;

		for (unsigned g = 0; g < 9; g++)
		{
			for (unsigned h = 0; h < 9; h++)
			{
				if (g == y)
					cout << board[g][h] << " ";
				if (h == x && g != y)
				{
					for (unsigned i = 0; i < h; cout << "  ", i++);
					cout << board[g][h];
				}
			}
			cout << endl;
		}
	}
	
	// Output of the entire line and information to it
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

	// Output whole board by unsigned 
	void PrintUnsignedBoardSudoku(vector<vector<vector<unsigned>>>& possible_nums)
	{
		for (unsigned i = 0; i < 9; i++)
		{
			for (unsigned j = 0; j < 9; j++)
			{
				if (possible_nums[i][j][0] == 0)
					cout << " ";
				else
					cout << possible_nums[i][j][0];
				cout << " ";
			}
			cout << endl;
		}
		cout << "\nPrintSudoku. End" << endl;
	}

	// Output whole original board 
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

	possible_nums = sl.First_fill(possible_nums, board);

	vector<vector<vector<unsigned>>> temp1 = possible_nums;
	
	unsigned unchanged = 0;

	unsigned k = 0;
	

	bool check = false;

	while (unchanged < 3) {

		possible_nums = sl.Check(possible_nums);

		if (possible_nums == temp1)
			unchanged++;
		else
		{
			cout << "Конец итерации #" << k << endl << endl;
			sl.CoutSudokuAndVar(possible_nums);
			cout << endl;
			sl.PrintUnsignedBoardSudoku(possible_nums);
			cout << endl;
			unchanged = 0;
		}
		temp1 = possible_nums;
		if (!check)
			cin >> check;
		k++;
	}

	return 0;
}





//sl.Write_Num(board, 0, 6); // Функция для вывода необхождимых строчек и стоблцов
// 
// 
//sl.CoutSudokuAndVar(possible_nums);
	//cout << "Set" << endl;
	//for (unsigned n : sl.Set_Uniq(possible_nums, 0, 6)) // Функция для сбора уникальных значений с строчек и столбцов
	//	cout << n << ' ';
	//cout << endl;


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


/*void Out_Square(unsigned y_start, unsigned x_start, vector<vector<vector<unsigned>>>& possible_nums)
	{
		for (unsigned temp_y = y_start; temp_y < (y_start + 3); temp_y++)
		{
			for (unsigned temp_x = x_start; temp_x < (x_start + 3); temp_x++)
			{
				cout << possible_nums[temp_y][temp_x][0] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}*/