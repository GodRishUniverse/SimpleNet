#include "Tensor.h"
#include "Matrix.h"


#include <iostream>
#include <algorithm>


namespace simplenet::activation_functions{
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


    Matrix relu(Matrix m) {
        Matrix result(m.getRows(), m.getCols());
        for (int i = 0; i < m.getRows(); i++) {
            for (int j = 0; j < m.getCols(); j++) {
                result.set(std::max(0.0, m.get(i, j)), i, j);
            }
        }    
    }

}

// Tensor implementation to be added
