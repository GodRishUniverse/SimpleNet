#pragma once

#include <iostream>
#include <utility>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int rows;
    int cols;
    double *data;

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
    Matrix(Matrix& other){
        this->rows = other.rows;
        this->cols = other.cols;
        this->data = new double[rows * cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                this->data[i * cols + j] = other.get(i, j);
            }
        }
    }

    // Copy assignment operator
    Matrix& operator=(const Matrix& other) {
        //TODO: Implement this method
    }

    // Move constructor
    Matrix(Matrix&& other) {
        this->rows = other.rows;
        this->cols = other.cols;
        std::swap(this->data, other.data);
        other.data = nullptr;
        other.rows = 0;
        other.cols = 0; 
    }

    // Move assignment operator
    Matrix&& operator=(const Matrix&& other) {
        //TODO: Implement this method
    }

    ~Matrix(){delete[] data;};
};

#endif // MATRIX_H
