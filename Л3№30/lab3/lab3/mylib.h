#pragma once
#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

struct MyStruct {

    unsigned short N : 8;
    unsigned short B : 1;
    unsigned short F : 1;
    unsigned short ZERO : 1;
    unsigned short C : 5;

    
};

void packData(MyStruct& data, unsigned int value);

bool checkInputValue(unsigned short value, unsigned short max);

void fillStruct(MyStruct& data, unsigned short C, unsigned short ZERO, unsigned short F, unsigned short B, unsigned short N);

void unpackStruct(const MyStruct& data, unsigned short& C, unsigned short& ZERO, unsigned short& F, unsigned short& B, unsigned short& N);