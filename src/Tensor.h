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

            double * getTensorDataFlat() const { return this->data; };
        public:
            // constructor when size and data are provided
            Tensor(std::vector<int> sizePassed) : shape(sizePassed) {
                ll total = 1; // cause size may be huge
                for (const int & i : shape){
                    total*= i;
                }
        
                // std::cout << "Total Size: " << total<< std::endl; 
        
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

            void printShape() const {
                std::cout << "Shape: [";
                for (ll i = 0; i < this->shape.size(); i++){
                    std::cout << this->shape[i];
                    if (i != this->shape.size()-1){
                        std::cout << ", ";
                    }
                }
                std::cout << "]" << std::endl;
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
        
        
            // friend function - add tensors    
            friend Tensor operator+(const Tensor &a, const Tensor &b) {
                if (a.shape != b.shape){
                    throw std::invalid_argument("Tensors must have the same shape");
                }
                Tensor result(a.shape);
                for (ll i = 0; i < a.sizeOfTensor(); i++){
                    result.data[i] = a.data[i] + b.data[i];
                }
                return result;
            }

            Tensor operator+=(const Tensor &other) {
                if (this->shape != other.shape){
                    throw std::invalid_argument("Tensors must have the same shape");
                }
                for (ll i = 0; i < other.sizeOfTensor(); i++){
                    other.data[i] += other.data[i];
                }
                return *this;
            }


            std::vector<int> getShape() const {
                return this->shape;
            }


            // TODO: friend function - print the tensor to be added
            friend std::ostream& operator<<(std::ostream& os, const Tensor& tensor) {
                int total_elements = 1;
                for (int dim : tensor.shape) {
                    total_elements *= dim;
                }

                os << "Tensor with shape: [";
                for (size_t i = 0; i < tensor.shape.size(); ++i) {
                    os << tensor.shape[i];
                    if (i != tensor.shape.size() - 1) os << ", ";
                }
                os << "]\n";

                os << "Tensor data: \n";
                for (int i = 0; i < total_elements; ++i) {
                    os << tensor.data[i] << " ";
                }
                os << std::endl;

                return os;
            }

            
        
            // friend function - subtract tensors
            friend Tensor operator-(const Tensor &a, const Tensor &b) {
                if (a.shape != b.shape){
                    throw std::invalid_argument("Tensors must have the same shape");
                }
                Tensor result(a.shape);
                for (ll i = 0; i < a.sizeOfTensor(); i++){
                    result.data[i] = a.data[i] - b.data[i];
                }
                return result;
            }

            Tensor operator-=(const Tensor &other) {
                if (this->shape != other.shape){
                    throw std::invalid_argument("Tensors must have the same shape");
                }
                for (ll i = 0; i < other.sizeOfTensor(); i++){
                    other.data[i] -= other.data[i];
                }
                return *this;
            }
        
            // TODO: friend function - multiply tensors - dot product
        
            // TODO: reshape 
    
            // flatten
            void flatten(){
                // We already have a 1D tensor
                std::vector<int> temp;
                ll total = 1;
                for (ll i = 0; i < this->shape.size(); i++){
                    total *= this->shape[i];
                }
                temp.push_back(total);
                this->shape = temp;
            }
        
            // TODO:unflatten
        
            // TODO: unsqueeze
        
            // TODO: squeeze
        
            // TODO:concat
            void concat(Tensor& other, int dim =0 ){
                auto otherDims = other.getShape();
                ll total = 1;
                for (ll i = 0; i < this->shape.size(); i++){
                    // check if the dimensions are the same                   
                    if (i!=dim && this->shape[i] != otherDims[i]){
                        throw std::invalid_argument("Tensors must have the same shape");
                    }

                    if (i == dim){
                        total *= (this->shape[i] + otherDims[i]);
                    }else{
                        total *= this->shape[i];
                    }
                }

                double * temp = new double[total];

                auto tempShape = this->shape;
                tempShape[dim] = this->shape[dim] + otherDims[dim];

                ll stride = 1;
                ll start = 0;

            
                for (ll j = dim+1; j < tempShape.size(); j++){
                    stride *= tempShape[j];
                }
                // figure out how to add the data first and then the other data
                for (ll j = 0; j < this->shape[dim]; j++){
                    // TODO: figure out how to add the data

                }
                start += this->shape[dim] * stride;

                for (ll j = 0; j < other.shape[dim]; j++){
                    // TODO: figure out how to add the data


                }
 
                
            }
        
            
            void stack(std::initializer_list<Tensor> tensors){
                if (tensors.size() == 0) {
                    throw std::invalid_argument("At least one tensor is required for stacking.");
                }

                for (const Tensor& tensor : tensors){
                    if (tensor.shape != this->shape){
                        throw std::invalid_argument("Tensors must have the same shape");
                    }
                }

                ll total = (tensors.size()+1) * this->sizeOfTensor();
                double * temp = new double[total];
                ll stride = this->sizeOfTensor();

                this->shape.insert(this->shape.begin(), tensors.size()+1);
                
                
                std::copy(this->data, this->data + stride, temp + 0);
                ll start = stride;
                for (const Tensor& tensor : tensors){
                    double * tempData = tensor.getTensorDataFlat();
                    
                    std::copy(tempData, tempData + stride, temp + start); // copy the data
                    start += stride;
                }
                
                
                if (this->data != nullptr) {
                    delete[] this->data;
                }
                this->data = temp;
            }
        
        
        };
        
}
#endif
