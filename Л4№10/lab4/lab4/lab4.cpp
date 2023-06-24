#include <iostream>


using namespace std;

void myInput(double& val);

bool checkZero(double first, double c) {

	return first - c == 0;
}

void ffunc(double a, double b, double c, double Xstart, double Xend,double dx) {

	double Xnow = Xstart;

	double f;
	
	cout << "print F(x)  [" << Xstart << ", " << Xend << "] with step " << dx << ":\n";

	while (Xnow <= Xend){

		if (Xnow < 3 && b != 0) {

			f = pow(Xnow, 2) * a - b * Xnow + c;
		}
		else if (Xnow > 3 && b == 0 && !checkZero(Xnow,c)) {

			f = (Xnow - a) / (Xnow - c);
		}
		else {

			if (c == 0) {

				cout << "Error";
				break;

			}

			f = Xnow / c;
		}

		Xnow += dx;
		cout << f << endl;

	}



}




int main() {

	double a, b, c, Xstart, Xend, dx;
	
	cout << "Enter a: ";

	myInput(a);

	cout << "Enter b: ";

	myInput(b);

	cout << "Enter c: ";

	myInput(c);

	cout << "Enter Xstart: ";

	myInput(Xstart);

	cout << "Enter Xend: ";

	myInput(Xend);

	cout << "Enter dx: ";

	myInput(dx);
	
	
	ffunc(a, b, c, Xstart, Xend, dx);

	cout << "\nTest1\n";
	// Тест 1: простой случай
	a = 1.0; b = 2.0; c = 3.0;
	Xstart = 0.0; Xend = 5.0; dx = 1.0;
	ffunc(a, b, c, Xstart, Xend, dx);

	cout << "\nTest2\n";
	// Тест 2: b = 0
	a = 1.0; b = 0.0; c = 3.0;
	Xstart = 0.0; Xend = 5.0; dx = 1.0;
	ffunc(a, b, c, Xstart, Xend, dx);

	cout << "\nTest3\n";
	// Тест 3: Xnow < 3 && b == 0
	a = 1.0; b = 0.0; c = 3.0;
	Xstart = 0.0; Xend = 2.0; dx = 1.0;
	ffunc(a, b, c, Xstart, Xend, dx);

	cout << "\nTest4\n";
	// Тест 4: Xnow > 3 && b != 0
	a = 1.0; b = 2.0; c = 3.0;
	Xstart = 4.0; Xend = 5.0; dx = 1.0;
	ffunc(a, b, c, Xstart, Xend, dx);


	return 0;
}


void myInput(double& val) {

	do {
		
		
		cin >> val;

		if (cin.fail()) {

			cout << "Error. Try again!";

			cin.clear();
			cin.ignore();
		}


	} while (cin.fail());
}