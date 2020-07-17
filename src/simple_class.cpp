/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT

SimpleClass demonstrates:
1. Different constructor types

*/
// header first
#include "simple_class.h"

// leave a space, c++ STL next
#include <string>

// leave a space, other headers
#include "constants.h"

namespace {
    // unnamed namespace is only accessible to this translation unit
    int free_variable = 0;  // this will be shared by all instances
    void FreeFunction(int arg) {
        free_variable += arg;
    }
}

namespace cpp_boilerplate {
int SimpleClass::class_attribute = 0;

void SimpleClass::ClassMethod() {
    // class method cannot read/write instance attribute
    // only the class attribute
    class_attribute += 1;
}

// The correct syntax to call parameterized constructer
// from default constructor.
// Never call another constructor inside the body
// of a constructor, which will call destructor first
SimpleClass::SimpleClass() : SimpleClass(0) {}

SimpleClass::SimpleClass(int arg)     // use initializer list to initialize:
            :kPublicAttribute(arg) {  // const variable
    // normal attribute can either be defined here or in initializer list
    private_attribute_ = kPublicAttribute;
    // instance function can read/write class variable
    class_attribute += 1;
}


std::string SimpleClass::PublicMethod(
    int arg, const std::string& message) const {
    // call free function
    FreeFunction(arg);
    // access free variable
    return message+":"+std::to_string(free_variable);
}

bool SimpleClass::PrivateMethod(int arg) const {
    // access constant defined in constants.h
    return arg > kSqrt2;
}

}  // namespace cpp_boilerplate
