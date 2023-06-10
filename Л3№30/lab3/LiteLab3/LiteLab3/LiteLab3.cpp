#include <iostream>

using namespace std;

void firstApp(unsigned short& data, unsigned short C, unsigned short ZERO, unsigned short F, unsigned short B, unsigned short N) {

	
	data = N;
	data = B << 8 | data;
	data = F << 9 | data;
	data = ZERO << 10 | data;
	data = C << 11 | data;

}

void secondApp(unsigned short& C, unsigned short& ZERO, unsigned short& F, unsigned short& B, unsigned short& N, unsigned short data) {


	


	N = data & 0xFF;
	B = (data >> 8) & 0x1;
	F = (data >> 9) & 0x1;
	ZERO = (data >> 10) & 0x1;
	C = (data >> 11) & 0x1F;
	
	cout << dec << "N =" << N << endl;
	cout << dec << "B =" << B << endl;
	cout << dec << "F =" << F << endl;
	cout << dec << "C =" << C << endl;


	cout << hex << data; // вывод числа в шестнадцатеричном виде


	
}


int main()
{
	unsigned short data = 0,C,F,B,N;
	unsigned short ZERO = 0;

	cout << "Enter C: [0-31]" << endl;
	cin >> C;

	cout << "Enter F: [0-1]" << endl;
	cin >> F;

	cout << "Enter B: [0-1]" << endl;
	cin >> B;

	cout << "Enter N: [0-255]" << endl;
	cin >> N;
	
	firstApp(data, C, ZERO, F, B, N);

	cout << "RESULT: 0x" << hex << uppercase << data<< endl;

	cout << "Enter a packed structure as a hexadecimal number (0x format): " << endl;

	cin >> hex >> data;

	
	secondApp(C, ZERO, F, B, N,data);

	return 0;



   
}


