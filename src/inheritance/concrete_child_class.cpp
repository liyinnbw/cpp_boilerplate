/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT
*/
#include "concrete_child_class.h"

#include <iostream>
#include <string>

namespace cpp_boilerplate {
// delegate default constructor to parameterized constructor
// note the parameterized constructor is invoked in initializer list
// NEVER call parameterized constructor from the default constructor body
// else the object will first be constructed in default and then
// destructed and then constructed in parameterized mode
//
// In practice, you may just have the parameterized constructor
// and provide default values to the parameters
ConcreteChildClass::ConcreteChildClass():ConcreteChildClass("Child"){
    // this will be called after parameterized constructor finished 
    std::cout << "ConcreteChildClass(default)" << std::endl;
}
ConcreteChildClass::ConcreteChildClass(const std::string& arg): 
    // since parent has default constructor, we don't need to explicitly
    // call the parent constructor with argument
    private_attribute(arg)
{
    std::cout << "ConcreteChildClass(1 param)"
        << "::private_attribute = "
        << private_attribute << std::endl;
}
// In practice, just need this constructor and provide defaults to the args
ConcreteChildClass::ConcreteChildClass(const std::string& parent_arg,const std::string& arg):
    // you can explicitly call parent constructor with param here
    // to have more control over initializing both parent and child attributes
    ConcreteClass(parent_arg),
    private_attribute(arg)
{
    std::cout << "ConcreteChildClass(2 params)"
        << "::private_attribute = "
        << private_attribute << std::endl;
}
ConcreteChildClass::~ConcreteChildClass() {
    std::cout << "~ConcreteChildClass" << std::endl;
}

std::string ConcreteChildClass::ConcreteChildPublicMethod(const std::string& arg) const {
    std::cout << ">>ConcreteChildClass::ConcreteChildPublicMethod" << std::endl;
    PrivateMethod(arg);
    ConcreteProtectedMethod(arg);
    std::cout << "<<ConcreteChildClass::ConcreteChildPublicMethod" << std::endl;
    return private_attribute;
}
std::string ConcreteChildClass::ConcreteMethodOverridable(const std::string& arg) const {
    std::cout << ">>ConcreteChildClass::ConcreteMethodOverridable" 
        << "::private_attribute = "
        << private_attribute << std::endl;
    
    // you may call parent method if you still want it
    ConcreteClass::ConcreteMethodOverridable(arg);
    
    std::cout << "<<ConcreteChildClass::ConcreteMethodOverridable" << std::endl;
    return private_attribute;
}
std::string ConcreteChildClass::PrivateMethod(const std::string& arg) const {
    std::cout << "ConcreteChildClass::PrivateMethod"
        << "::private_attribute = "
        << private_attribute << std::endl;
    return private_attribute;
}
}  // namespace cpp_boilerplate
