# include "Matrix.h"


// matrix addition
Matrix Matrix::operator+(const Matrix &other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.set(i, j, this->get(i, j) + other.get(i, j));
        }
    }
    return result;
}

//copy assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        delete[] data;
        this->rows = other.rows;
        this->cols = other.cols;
        this->data = new double[rows * cols];
        std::copy(other.data, other.data + rows * cols, this->data);
    }
    return *this;
}

// move assignment operator
Matrix&& Matrix::operator=( Matrix&& other) {
    if (this != &other) {
        delete[] data;
        this->rows = other.rows;
        this->cols = other.cols;
        this->data = other.data;
        other.data = nullptr;
    }
    return std::move(*this);
}

// scalar multiplication
Matrix& Matrix::operator*=(double scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->data[i * cols + j] *= scalar;
        }
    }
    return *this;
}


// matrix multiplication
Matrix Matrix::operator*(Matrix&  mat) const {
    // TODO: implement matrix multiplication - use CUDA if possible - to make it faster
}

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
