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



char* substring(char* cStr, int start, int length);

int main()
{
	std::cout << "Enter the string :";
	
	const int lengthBufferSize = 1001;

	char* cStr = new char[lengthBufferSize];

	std::cin.getline(cStr,lengthBufferSize);

	std::cout << "Enter start position for start substring: ";
	
	int startP;

	std::cin >> startP;

	cStr = substring(cStr, startP, lengthBufferSize);
	
	std::cout << cStr;

	delete[] cStr;


	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	return 0;

	}


char* substring(char* cStr, int start, int length) {
	
	char* result = new char[length+1];
	int index = 0;
	
	for (int i = start; i < length; i++)
	{
		result[index] = cStr[i];
		if (cStr[i] == '\0') {
			break;
		}

		index++;
	}
	
	delete[] cStr;
	
	
	return result;

}