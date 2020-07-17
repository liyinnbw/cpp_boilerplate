/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT

SimpleClass demonstrates:
1. Different constructor types
2. Class, public, private attributes
3. Class, public, private methods
4. Free variable and function in .cpp
5. Use of constants defined elsewhere in .cpp
*/
#ifndef SRC_SIMPLE_CLASS_H_
#define SRC_SIMPLE_CLASS_H_

#include <string>

namespace cpp_boilerplate {
class SimpleClass {
    // declare friend class for gtest case TEST(SimpleClass, PrivateMethod)
    // friend class need not to be declared under private or public
    // However, try not to test private method if it can be easily
    // tested through other existing public method.
    friend class SimpleClass_PrivateMethod_Test;

 public:
    // class attribute shared among instances
    static int class_attribute;

    // class method which can only modify class attribute
    static void ClassMethod();

    // default constructor
    SimpleClass();

    // parameterized constructor
    // "explicit" prevents implicit parameter type cast at compile time
    explicit SimpleClass(int arg);

    // always make destructor virtual to guard against memory leak
    // when unintentionally invoke parent destructor without
    // invoking child destructor
    virtual ~SimpleClass() {}

    // public method
    // "arg" is pass by value, does not require "const" keyword
    // "message" is pass by reference, use "const" to guard modification
    // the ending "const" guard against modifying attributes
    std::string PublicMethod(int arg, const std::string& message) const;

    // getter and setters of private attribute
    // "inline" can be used on really short functions (<=10 lines)
    // "inline" may not be honoured by the compiler,
    // e.g. virtual and recursive functions
    // "inline" is not worth it if function contains loop/switch
    inline int GetPrivateAttribute() const {return private_attribute_;}
    inline void SetPrivateAttribute(int value) {private_attribute_ = value;}

    // avoid using public attribute, unless it is constant
    // note naming convention of constants
    const int kPublicAttribute;

 private:
    // private method
    bool PrivateMethod(int arg) const;
    // note naming convention of private attribute
    int private_attribute_;
};
}  // namespace cpp_boilerplate

#endif  // SRC_SIMPLE_CLASS_H_
