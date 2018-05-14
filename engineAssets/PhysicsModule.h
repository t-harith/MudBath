
//
//  PhysicsCompute.h
//
//
//  Created by Tejas Harith on 5/13/18.
//

#ifndef PhysicsCompute_h
#define PhysicsCompute_h


#endif /* PhysicsCompute_h */

#include <iostream>

class PhysicsCompute
{
private:
    int state;
public:
    PhysicsCompute()
    :state(-1){
        std::cout << "PhysicsCompute Constructor" << std::endl;
    }
    ~PhysicsCompute()
    {
        std::cout << "PhysicsCompute Destructor" << std::endl;
    }
};
