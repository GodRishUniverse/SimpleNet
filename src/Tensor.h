#pragma once

#include "Matrix.h"

#ifndef TENSOR_H
#define TENSOR_H

class Tensor {
private:
    int * size;
    double * data;
public:
    // constructor when size and data are provided
    Tensor(int * size, double * data): size(size), data(data) {
    };

    // constructor when only size is provided
    Tensor(int * size): size(size) {
        int totalSize = 1;
        for (int i = 0; i < sizeof(size)/sizeof(size[0]); i++) {
            totalSize *= size[i];
        }
        this->data = new double[totalSize];
    };


    int * getSize() const {
        return this->size;
    }

    ~Tensor() {
        delete[] data;
        delete[] size;
    };
};
#endif
