#include "Tensor.h"
#include "Matrix.h"
#include <random>


// Xavier initialization


Matrix linear(Matrix m1, int outrows) {
    // need a way to initialize the weight matrix here.
    int inrows = m1.getRows();
    int incols = m1.getCols();

    // outcols = inrows
    int outcols = inrows;

    Matrix weight= Matrix::xavier(outrows, inrows, inrows * incols, outrows * outcols); // get the weight matrix
    Matrix bias = Matrix::xavier(outrows, inrows, inrows * incols, outrows * outcols); // get the bias

    Matrix result = (weight * m1) + bias; 
    return result;
}

// Tensor implementation to be added
