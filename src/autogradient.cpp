#include <algorithm>
#include <vector>

#include "Tensor.h"
#include "Matrix.h"

using namespace std;




// Will use reverse accumulation of gradients-  https://en.wikipedia.org/wiki/Automatic_differentiation  
namespace simplenet{


     struct Expression {

     };

     struct Variable: public Expression {
        
     };
     struct Plus: public Expression {
        
     };
     struct Multiply: public Expression {
       
     };
}
namespace simplenet::autogradient{
    // TODO : Add autograd
}
