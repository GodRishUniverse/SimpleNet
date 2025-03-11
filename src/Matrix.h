#pragma once

#include <iostream>
#include <utility>
#include <ostream>

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
        for (int i = 0; i < rows * cols; i++) {
            this->data[i] = 0;
        }
    };

    Matrix(std::initializer_list<std::initializer_list<double>> dataPassed) : rows(dataPassed.size()), cols(dataPassed.begin()->size()), data(new double[rows * cols]) {
        int i = 0;
        int j = 0;

        for (const auto& row : dataPassed) {
            for (const auto& elem : row) {
                this->data[i * cols + j] = elem;
                j++;
            }
            i++;
            j = 0;
        }
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

    // transpose the matrix
    void transpose();

    // swap columns
    void swapCols(int col1, int col2);

    // swap rows
    void swapRows(int row1, int row2);

    // matrix addition
    Matrix operator+(const Matrix &other) const ;

    // matrix addition
     void operator+=(Matrix &other) ;

    // Copy constructor
    Matrix(Matrix& other);

    // Copy assignment operator
    Matrix& operator=(const Matrix& other);

    // Move constructor
    Matrix(Matrix&& other);

    // Move assignment operator
    Matrix&& operator=( Matrix&& other);

    // scalar multiplication
    Matrix& operator*=(double scalar);
    // matrix multiplication
    Matrix operator*(Matrix&  mat) const;
    // destructor
    ~Matrix(){delete[] data;};
    // print helper
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

#endif // MATRIX_H
