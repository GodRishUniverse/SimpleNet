#include "Tensor.h"
#include "Matrix.h"

#include <iostream>
#include <algorithm>

Matrix relu(Matrix m) {
    Matrix result(m.getRows(), m.getCols());
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            result.set(std::max(0.0, m.get(i, j)), i, j);
        }
    }    
}


// Tensor implementation to be added
