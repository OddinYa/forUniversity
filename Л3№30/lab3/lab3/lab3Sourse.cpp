/*#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

struct MyStruct {

    unsigned short C : 7;
    unsigned short F : 1;
    unsigned short B : 1;
    unsigned short N : 7;
};

void packData(MyStruct& data, unsigned short value) {
    
    if (bitset<16>(value).count() == 16) {

    data.C = (value >> 9) & 0x7F;  
    data.F = (value >> 8) & 0x01;  
    data.B = (value >> 7) & 0x01;  
    data.N = value & 0x7F; 
    }
    else
    {
        throw invalid_argument("Error: Invalid input");
    }

            
}

bool checkInputValue(unsigned short value, unsigned short max) {

    return (value > max);
}

void fillStruct(MyStruct& data, unsigned short C, unsigned short F, unsigned short B, unsigned short N) {

    data.C = C & 0x7F;
    data.F = F & 0x01;
    data.B = B & 0x01;
    data.N = N & 0x7F;
}

void unpackStruct(const MyStruct& data, unsigned short& C, unsigned short& F, unsigned short& B, unsigned short& N) {

    C = data.C;
    F = data.F;
    B = data.B;
    N = data.N;
    C |= (F << 1);
    N |= (B << 1);
}

int sourse() {

    MyStruct data;
    unsigned short C, F, B, N;

    cout << "Enter C: ";
    cin >> C;
    while (true) {

        if (checkInputValue(C, 127)) {

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

        if (checkInputValue(N, 127)) {

            cout << "Enter N: ";
            cin >> N;
        }
        else {
            break;
        }
    }

    fillStruct(data, C, F, B, N);
    cout << "RESULT: 0x" << hex << setfill('0') << setw(4) << uppercase << *(unsigned short*)&data << endl;
    
    cout << "RESULT:" << bitset<7>(C) << " " << bitset<1>(F) << " " << bitset<1>(B) << " " << bitset<7>(N) << endl;

    unpackStruct(data, C, F, B, N);
    cout << "C: " << dec << C << endl;
    cout << "F: " << dec << F << endl;
    cout << "B: " << dec << B << endl;
    cout << "N: " << dec << N << endl;

    cout << "Tests" << endl;
    try
    {
        packData(data, 0xFFFF);

        unpackStruct(data, C, F, B, N);

        cout << "C: " << dec << C << endl;
        cout << "F: " << dec << F << endl;
        cout << "B: " << dec << B << endl;
        cout << "N: " << dec << N << endl;
    }
    catch (exception&)
    {
        cout << "Error: Invalid input";
    }
   


    return 0;
}*/