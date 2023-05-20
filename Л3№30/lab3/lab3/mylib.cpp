#include "mylib.h"

void packData(MyStruct& data,unsigned int valueIn) {

    try {
        unsigned short valueTry = 0xFFFF;

        if (valueIn > valueTry) {

            throw invalid_argument("Error: Invalid input");

        }
        
        data.C = (valueIn >> 11) & 0x1F;
        data.ZERO = (valueIn >> 10) & 0x01;
        data.F = (valueIn >> 9) & 0x01;
        data.B = (valueIn >> 8) & 0x01;
        data.N = valueIn & 0xFF;

        if (data.ZERO != 0) {

            throw invalid_argument("Error: Invalid input");

        }
    }
    catch (exception e) {

        cout << "Error: Invalid input";
        exit(-1);
    }
   
}

bool checkInputValue(unsigned short value, unsigned short max) {

    return (value > max);
}

void fillStruct(MyStruct& data, unsigned short C, unsigned short ZERO, unsigned short F, unsigned short B, unsigned short N) {

    data.C = C & 0x1F;
    data.ZERO = ZERO & 0x01;
    data.F = F & 0x01;
    data.B = B & 0x01;
    data.N = N & 0xFF;
}

void unpackStruct(const MyStruct& data, unsigned short& C, unsigned short& ZERO, unsigned short& F, unsigned short& B, unsigned short& N) {

    C = data.C;
    F = data.F;
    B = data.B;
    ZERO = data.ZERO;
    N = data.N;
    
}