#include <iostream>

using namespace std;


bool CheckPointHit(float x, float y) {

	bool checkInsideCircle = (pow(x, 2) + pow(y, 2) <= pow(1, 2))&&(x <= 0 && y <= 0);
	bool checkInsideSquare = ((x <= 0 && x >= -1) && (y >= 0 && y <= 1));

	return checkInsideCircle || checkInsideSquare;

}



int main() {

	float x;
	float y;
	
	while (true) {

		try {

			cout << "Enter X: ";
			cin >> x;

			if (cin.fail()) {

				cin.clear();
				cin.ignore(256, '\n');
				throw runtime_error("Invalid input");
			}
			
			cout << "Enter Y: ";
			cin >> y;

			if (cin.fail()) {

				cin.clear();
				cin.ignore(256, '\n');
				throw runtime_error("Invalid input");
			}

			break;
		}
		catch (exception e) {
			
			cout << "Invalid input, try agane" << endl;
			
		}
	}

	if (pointHit(x, y)) {

		cout << "Yes";
	}
	else{

		cout << "No";
	}
	
	return 0;
}

