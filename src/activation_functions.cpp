#include "Tensor.h"
#include "Matrix.h"


#include <iostream>
#include <algorithm>


namespace simplenet::activation_functions{

    // Linear
    template<typename T>
    Matrix<T> linear(Matrix<T> &m1, int outrows) {
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

    // Sigmoid
    double sigmoid(double x) {
        return 1.0 / (1.0 + exp(-x));
    }

    template<typename T>
    Matrix<T> sigmoid(Matrix<T> &m) {
        Matrix<T> result(m.getRows(), m.getCols());
        for (int i = 0; i < m.getRows(); i++) {
            for (int j = 0; j < m.getCols(); j++) {
                result.set(1.0/(1.0 + exp(-m.get(i, j))),i,j);
            }
        }    
    }

    // ReLU
    double relu(double x) {
        return std::max(0.0, x);
    }

    template<typename T>
    Matrix<T> relu(Matrix<T> &m) {
        Matrix<T> result(m.getRows(), m.getCols());
        for (int i = 0; i < m.getRows(); i++) {
            for (int j = 0; j < m.getCols(); j++) {
                result.set(std::max(0.0, m.get(i, j)), i, j);
            }
        }    
    }

    // Leaky ReLU
    double leaky_relu(double x, double leaky) {
        return std::max(leaky * x, x);
    }

    template<typename T>
    Matrix<T> leaky_relu(Matrix<T> &m, double leaky) {
        Matrix<T> result(m.getRows(), m.getCols());
        for (int i = 0; i < m.getRows(); i++) {
            for (int j = 0; j < m.getCols(); j++) {
                result.set(std::max(leaky * m.get(i, j), m.get(i, j)), i, j);
            }
        }    
    }

}

// Tensor implementation to be added
