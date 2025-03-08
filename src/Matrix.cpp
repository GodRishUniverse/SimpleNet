# include "Matrix.h"


Matrix::Matrix(Matrix& other){
    this->rows = other.rows;
    this->cols = other.cols;
    this->data = new double[rows * cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->data[i * cols + j] = other.get(i, j);
        }
    }
}

Matrix::Matrix(Matrix &&other) {
    this->rows = other.rows;
    this->cols = other.cols;
    std::swap(this->data, other.data);
    other.data = nullptr;
    other.rows = 0;
    other.cols = 0; 
}
