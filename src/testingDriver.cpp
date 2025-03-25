#include "Matrix.cpp"
#include "Tensor.cpp"

#include <iostream>
using namespace std;

int main() {

    // Matrix m1(4,4);
    // cout << m1 << endl;
    // Matrix m2(4,4);
    // cout << m2 << endl;

    simplenet::Matrix<int> m3 {{1, 2}, {5, 6}, {9, 10}, {13, 14}};

    cout << m3 << endl;

    simplenet::Matrix<int> m4({{1,4,5,6}, {7,8,9,10}});

    simplenet::Matrix<int> m6({{1,4,5,6}, {7,8,9,10}});

    cout << m4 << endl;

    simplenet::Matrix<int> m5 = m3 * m4;

    cout << m5 << endl;

    vector<int> size; 
    size.push_back(2);
    size.push_back(3);
    size.push_back(2);
    simplenet::Tensor t{size};
    cout << t << endl;
    simplenet::Tensor t2{size};
    cout << t2 << endl;
    simplenet::Tensor t3{size};
    cout << t3 << endl;

    t.stack({t2, t3});
    t.printShape();

    cout << t << endl;

    cout << m4 + m6 << endl;


}
