#include <algorithm>
#include <vector>

#include "Tensor.h"
#include "Matrix.h"

using namespace std;




// Will use reverse mode -  https://en.wikipedia.org/wiki/Automatic_differentiation  
// https://rufflewind.com/2016-12-30/reverse-mode-automatic-differentiation
namespace simplenet{
    // TODO: This is just a placeholder for now

    // NOtes for implementation 
    /*

    We will be using a topological sort to walk the graph and compute the derivatives
    We will design a computational graph and use a topological sort

    
    https://en.wikipedia.org/wiki/Topological_sort
    
    */


    // binary operations 
    struct Node {
        double weights[2];
        size_t deps[2]; 
    };

    class Variable {
        size_t index;
        double value;
        std::vector<Node*> nodes; // store the pointers to the nodes to reduce the memory usage
    public:
        Variable(size_t index, double value) : index(index), value(value) {}

        void addNode(Node* node) {
            nodes.push_back(node);
        }

        friend Variable operator+(Variable a, Variable b) {
            Variable result(a.index, a.value + b.value);
            // TODO: 
        }

        operator const double() const {
            return value;
        }
    };
    

}
namespace simplenet::autogradient{


}
