#include <iostream>
#include <iomanip>
#include "firstApp.h"


using namespace std;

void firstApp() {

    MyStruct data;
    unsigned short C, F, B, N;

    cout << "Enter C: ";
    cin >> C;
    while (true) {

        if (checkInputValue(C, 31)) {

            cout << "Enter C: ";
            cin >> C;
        }
        else {
            break;
        }
    }

    cout << "Enter F: ";
    cin >> F;
    while (true) {
        if (checkInputValue(F, 1)) {

            cout << "Enter F: ";
            cin >> F;
        }
        else {
            break;
        }
    }

    cout << "Enter B: ";
    cin >> B;
    while (true) {
        if (checkInputValue(B, 1)) {

            cout << "Enter B: ";
            cin >> B;
        }
        else {
            break;
        }
    }

    cout << "Enter N: ";
    cin >> N;
    while (true) {

        if (checkInputValue(N, 255)) {

            cout << "Enter N: ";
            cin >> N;
        }
        else {
            break;
        }
    }

    fillStruct(data, C, 0, F, B, N);
    cout << "RESULT: 0x" << hex << setfill('0') << setw(4) << uppercase << *(unsigned short*)&data << endl;

    

   }

   