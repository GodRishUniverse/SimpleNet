#include "Matrix.cpp"
#include "Tensor.h"

#include <iostream>
using namespace std;

int main() {

    // Matrix m1(4,4);
    // cout << m1 << endl;
    // Matrix m2(4,4);
    // cout << m2 << endl;

    Matrix m3 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    cout << m3 << endl;

    m3.transpose();

    cout << m3 << endl;

    Matrix m4({{1,4,5,6}, {7,8,9,10}, {11,12,13,14}, {15,16,17,18}});

    m3+=m4;

    cout << m3 << endl;

}
