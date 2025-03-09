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


    void swapCols(int col1, int col2);

    void swapRows(int row1, int row2);

    Matrix operator+(const Matrix &other) const ;

    // Copy constructor
    Matrix(Matrix& other);

    // Copy assignment operator
    Matrix& operator=(const Matrix& other);

    // Move constructor
    Matrix(Matrix&& other);

    // Move assignment operator
    Matrix&& operator=( Matrix&& other);


    Matrix& operator*=(double scalar);

    Matrix operator*(Matrix&  mat) const;

    ~Matrix(){delete[] data;};
};

#endif // MATRIX_H
