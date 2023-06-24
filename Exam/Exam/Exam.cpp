#include <iostream>


double swithArifmetic(char val, double first, double second);

double sum(double, double);

double multiplication(double, double);

double minus(double, double);

double division(double, double);

int main()
{
    char action;
                                                                                                                                                                                        
    double firstVal;
    double secondVal;

    std::cout << "ENTER Arithmetic operation: ";
    std::cin >> action;
    std::cout << std::endl;

    std::cout << "ENTER FIRST Numb : ";
    std::cin >> firstVal;
    std::cout << std::endl;

    std::cout << "ENTER SECOND Numb : ";
    std::cin >> secondVal;
    std::cout << std::endl;


    if (action == '/' && secondVal == 0) {
        
        std::cout << "Arethmetic Error";
    }
    else {

        std::cout << "Answer :";

        std::cout << swithArifmetic(action, firstVal, secondVal);
    }

     return 0;
}

double swithArifmetic(char val,double first,double second) {

    switch (val) {
    case '+':
        return sum(first,second);
    case '-':
        return minus(first,second);
    case '*':
        return multiplication(first,second);
    case '/':
        return division(first,second);
    }
}

double sum(double a, double b)
{
    return a+b;
}

double multiplication(double a, double b)
{
    return a*b;
}

double minus(double a, double b)
{
    return a-b;
}

double division(double a, double b)
{
    return a / b;
   
}


