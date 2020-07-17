/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT
*/
#include "concrete_class.h"

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
ConcreteClass::ConcreteClass():ConcreteClass("Parent"){
    // this will be called after parameterized constructor finished
    std::cout << "ConcreteClass(default)" << std::endl;
}
ConcreteClass::ConcreteClass(const std::string& arg):private_attribute(arg) {
    std::cout << "ConcreteClass(parameterized)"
        << "::private_attribute = "
        << private_attribute << std::endl;
}
ConcreteClass::~ConcreteClass() {
    std::cout << "~ConcreteClass" << std::endl;
}
std::string ConcreteClass::InterfaceMethodA(const std::string& arg) const {
    std::cout << "ConcreteClass::InterfaceMethodA" 
        << "::private_attribute = "
        << private_attribute << std::endl;
    return private_attribute;
}
std::string ConcreteClass::InterfaceMethodB(const std::string& arg) const {
    std::cout << "ConcreteClass::InterfaceMethodB"
        << "::private_attribute = "
        << private_attribute << std::endl;
    return private_attribute;
}
std::string ConcreteClass::ConcretePublicMethod(const std::string& arg) const {
    std::cout << ">>ConcreteClass::ConcretePublicMethod" << std::endl;
    PrivateMethod(arg);
    ConcreteProtectedMethod(arg);
    std::cout << "<<ConcreteClass::ConcretePublicMethod" << std::endl;
    return private_attribute;
}
std::string ConcreteClass::ConcreteMethodOverridable(const std::string& arg) const {
    std::cout << "ConcreteClass::ConcreteMethodOverridable" 
        << "::private_attribute = "
        << private_attribute << std::endl;
    return private_attribute;
}
std::string ConcreteClass::ConcreteProtectedMethod(const std::string& arg) const {
    std::cout << "ConcreteClass::ConcreteProtectedMethod"
        << "::private_attribute = "
        << private_attribute << std::endl;
    return private_attribute;
}
std::string ConcreteClass::PrivateMethod(const std::string& arg) const {
    std::cout << "ConcreteClass::PrivateMethod"
        << "::private_attribute = "
        << private_attribute << std::endl;
    return private_attribute;
}
}  // namespace cpp_boilerplate
