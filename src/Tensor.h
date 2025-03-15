#pragma once
#include <vector>
#include <iostream>

using ll = long long;


#ifndef TENSOR_H
#define TENSOR_H
namespace simplenet{
    class Tensor {
        private:
            std::vector<int> shape;
            double * data;
        public:
            // constructor when size and data are provided
            Tensor(std::vector<int> sizePassed) : shape(sizePassed) {
                ll total = 1; // cause size may be huge
                for (const int & i : shape){
                    total*= i;
                }
        
                std::cout << "Total Size: " << total<< std::endl; 
        
                data = new double[total]; 
                for (ll start = 0; start<total; start++){
                    data[start] = 0.0;
                }
            };
        
            double get(std::vector<int> index) const {
                if (index.size() != shape.size()){
                    throw std::invalid_argument("Invalid index size");
                }
        
                ll stride = 1;
                ll start = 0;
                for (ll i = 0; i < index.size(); i++){
                    stride *= shape[i];
                    start += index[i] * stride;
                }
        
                return data[start];
            }
        
        
            void set(double val, std::vector<int> index) const {
                if (index.size() != shape.size()){
                    throw std::invalid_argument("Invalid index size");
                }
        
                ll stride = 1;
                ll start = 0;
                for (ll i = 0; i < index.size(); i++){
                    stride *= shape[i];
                    start += index[i] * stride;
                }
        
                data[start] = val;
            }
            // helper function
            ll sizeOfTensor() const {
                ll total = 1; // cause size may be huge
                for (const int & i : shape){
                    total*= i;
                }
                return total;
            }
        
            // copy constructor
            Tensor(const Tensor& other) {
                this->shape = other.shape;
                this->data = new double[other.sizeOfTensor()];
                std::copy(other.data, other.data + other.sizeOfTensor(), this->data);
            }
        
            // copy assignment operator
            Tensor& operator=(const Tensor& other) {
                if (this != &other) {
                    delete[] data;
                    this->shape = other.shape;
                    this->data = new double[other.sizeOfTensor()];
                    std::copy(other.data, other.data + other.sizeOfTensor(), this->data);
                }
                return *this;
            }
        
            // move constructor
            Tensor(Tensor&& other) {
                this->shape = other.shape;
                this->data = other.data;
                other.data = nullptr;
            }
        
            // move assignment operator
            Tensor& operator=(Tensor&& other) {
                if (this != &other) {
                    delete[] data;
                    this->shape = other.shape;
                    this->data = other.data;
                    other.data = nullptr;
                }
                return *this;
            }
        
            // destructor
            ~Tensor(){
                delete[] data;
            }
        
            // friend function - print the tensor to be added
        
            // friend function - add tensors
        
            // friend function - subtract tensors
        
            // friend function - multiply tensors - dot product
        
            // reshape 
        
            // transpose
        
            // flatten
        
            // unflatten
        
            // unsqueeze
        
            // squeeze
        
            // concat
        
            // stack    
        
        
        };
        
}
#endif
