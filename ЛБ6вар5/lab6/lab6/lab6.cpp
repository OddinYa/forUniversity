#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif

#include <iostream>



int sumWithoutMinus(int **arr,int row,int line);
int** createArray(int rows, int line);
void deletArray(int	**arr, int rows);
int sumElementsDiagonal(int** arr, int rows, int line);

void print(int** arr, int rowsSize, int lineSize);	

int main()
{	
	int rows, line;

	std::cout << "Enter the dimension of the matrix NxN" << std::endl;
	std::cout << "Enter N:";

	std::cin >> rows;
	std::cout << std::endl;

	line = rows;

	int** newArr = createArray(rows, line);

	print(newArr, rows, line);

	std::cout << "\n";
	std::cout << "Sum whiout minus elements: " << sumWithoutMinus(newArr, rows, line) << std::endl;
	std::cout << "Sum Elements Diagonals: " << sumElementsDiagonal(newArr, rows, line);  

	deletArray(newArr,rows);
	newArr = nullptr;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	return 0;
}

int sumWithoutMinus(int** arr, int rows, int line) {
	int result = 0;

	for (int i = 0; i < line; i++) {
		bool hasNegative = false;

		for (int j = 0; j < rows; j++) {
			if (arr[j][i] < 0) {
				hasNegative = true;
				break;
			}
		}

		if (!hasNegative) {
			for (int j = 0; j < rows; j++) {
				result += arr[j][i];
			}
		}
	}

	return result;
}

int** createArray(int rows, int line){
	int nums;

	int** arr = new int* [line];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[line];
		std::cout << "Enter numbers in a line" << std::endl;
			for (int j = 0; j < line; j++)
			{	

				std::cin >> nums;
				arr[i][j] = nums;

			}
		std::cout << "Next row" << std::endl;
	}
	return arr;

}

void deletArray(int** arr, int rows){

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}


int sumElementsDiagonal(int** arr, int rowsSize, int lineSize) {
	
	int result = 0;
	
	int minSumLeft = INT_MAX;
	int minSumRight = INT_MAX;


	if (rowsSize <= 1 || lineSize <= 1 ) {
		std::cout << "Error. return: 0";
		return 0;
	}
	
	for (int i = 0, y = lineSize - 2; y >= 0;y--) {

		for (int k = i,j = y; k < rowsSize-1 && j>=0;) {

			for (; j >= 0;j--,k++)
			{
			    result += abs(arr[k][j]);
			}


		}
		if (result < minSumLeft) {
			minSumLeft = result;
			result = 0;
		}
	}
	
	result = 0;

	for (int i = 1, y = lineSize-1; i < rowsSize; i++) {

		for (int k = i; k < rowsSize;) {

			

			for (int j = y; k < rowsSize; k++,j--)
			{
				result += abs(arr[k][j]);
			}
		}
		if (result < minSumRight) {
			minSumRight = result;
			result = 0;
		}
	}
	
	if (minSumRight < minSumLeft) {
		return minSumRight;
	}
	
return minSumLeft;
}

void print(int** arr,int rowsSize,int lineSize) {

	for (int i = 0; i < rowsSize; i++) {
		
		std::cout << '\n';

		for (int j = 0; j < lineSize; j++)
		{
			std::cout << arr[i][j] << '\t';
		}

	}
}



