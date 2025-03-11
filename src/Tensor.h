#pragma once

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
        for (int i = 0; i < totalSize; i++) {
            this->data[i] = 0;
        }
    };

    double getData(int * indices) const {
        if (sizeof(indices)/sizeof(indices[0] != sizeof(size)/sizeof(size[0]))) {
            throw std::runtime_error("Index size mismatch");
            return 0;
        }

        // TODO: implement index checking and one dimensional index checking
    }


    int * getSize() const {
        return this->size;
    }

    ~Tensor() {
        delete[] data;
        delete[] size;
    };
};

#endif
