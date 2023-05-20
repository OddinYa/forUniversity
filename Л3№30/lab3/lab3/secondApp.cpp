#include <iostream>
#include <iomanip>
#include <sstream>

#include "secondApp.h"


using namespace std;

void secondApp() {

    MyStruct data;
    unsigned short C, F, B, N,ZERO;

    
    

    cout << "Enter a packed structure as a hexadecimal number (0x format): ";

    unsigned int bitInt;

    cin >> hex >> bitInt;

    packData(data,bitInt);
    
    unpackStruct(data, C, ZERO, F, B, N);

    cout << "C: " << dec << C << endl;
    cout << "F: " << dec << F << endl;
    cout << "B: " << dec << B << endl;
    cout << "N: " << dec << N << endl;

    
}





