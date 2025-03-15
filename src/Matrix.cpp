# include "Matrix.h"

#include <random>

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

void Matrix::operator+=( Matrix &other)  {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->data[i * cols + j] += other.get(i, j);
        }
    }
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
    // TODO: use CUDA if possible - to make it faster
    Matrix result(rows, mat.getCols());
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            double sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += this->get(i, k) * mat.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
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


void Matrix::swapCols(int col1, int col2){
    if (col1 < 0 || col1 >= this->cols || col2 < 0 || col2 >= this->cols) {
        std::cerr << "Invalid column indices" << std::endl;
        return;
    }

    for (int i = 0; i < this->rows; i++) {
        std::swap(this->data[i * this->cols + col1], this->data[i * this->cols + col2]);
    }
}


void Matrix::swapRows(int row1, int row2){
    if (row1 < 0 || row1 >= this->rows || row2 < 0 || row2 >= this->rows) {
        std::cerr << "Invalid row indices" << std::endl;
        return;
    }

    for (int j = 0; j < this->cols; j++) {
        std::swap(this->data[row1 * this->cols + j], this->data[row2 * this->cols + j]);
    }    
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.get(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}


void Matrix::transpose(){
    // rows will be cols and cols will be rows
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            std::swap(this->data[i * cols + j], this->data[j * cols + i]);
        }
    }
}

// Xavier initialization
static Matrix xavier(int inrows, int incols, int input_size, int output_size) {

    std::random_device rd{};
    std::mt19937 gen{rd()};
 

    float stddev = sqrt(2.0 / (input_size + output_size));

    std::normal_distribution<double> d{0.0,stddev};

    Matrix m(inrows, incols);
    for (int i = 0; i < inrows; i++) {
        for (int j = 0; j < incols; j++) {
            m.set(i, j, d(gen));
        }
    }
    return m;
} 
