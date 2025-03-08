#pragma once

#include <iostream>
#include <utility>

#ifndef MATRIX_H
#define MATRIX_H

// TODO: Templatify Matrix class so that it can work with any data type

class Matrix
{
private:
    int rows;
    int cols;
    double *data; // flattened representation of the matrix

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols), data(new double[rows * cols]) {
    };

    int getRows() const {
        return this->rows;
    }

    int getCols() const {
        return this->cols;
    }

    double get(int i, int j) const {
        return this->data[i * cols + j];
    }

    void set(int i, int j, double value) {
        this->data[i * cols + j] = value;
    }

    Matrix operator+(const Matrix &other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.set(i, j, this->get(i, j) + other.get(i, j));
            }
        }
        return result;
    }

    // Copy constructor
    Matrix(Matrix& other);

    // Copy assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            delete[] data;
            this->rows = other.rows;
            this->cols = other.cols;
            this->data = new double[rows * cols];
            std::copy(other.data, other.data + rows * cols, this->data);
        }
        return *this;
    }

    // Move constructor
    Matrix(Matrix&& other);

    // Move assignment operator
    Matrix&& operator=( Matrix&& other) {
        if (this != &other) {
            delete[] data;
            this->rows = other.rows;
            this->cols = other.cols;
            this->data = other.data;
            other.data = nullptr;
        }
        return std::move(*this);
    }


    Matrix& operator*=(double scalar) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                this->data[i * cols + j] *= scalar;
            }
        }
        return *this;
    }

    Matrix operator*(Matrix&  mat) const {
        // TODO: implement matrix multiplication - use CUDA if possible
    }

    ~Matrix(){delete[] data;};
};

#endif // MATRIX_H
