#include <iostream>
#include <math.h>

using namespace std;



float calcFirstForm(int n, int m) {

    float dividend = (m - 1) * sqrt(m) - (n - 1) * sqrt(n);
    float divider = sqrt(pow(m, 3) * n) + n * m + pow(m, 2) - m;

    return dividend / divider;
}

float calcSecondForm(int n, int m) {

    float dividend = (sqrt(m) - sqrt(n));
    float divider = m;

    return dividend / divider;
}

int main() {

    int n;
    int m;

    cin >> n >> m;

    printf("First formula: %f \n", (calcFirstForm(n, m)));
    printf("Second formula:  %f", (calcSecondForm(n, m)));

    return 0;
}



