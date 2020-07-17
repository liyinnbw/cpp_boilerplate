/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT

Abstract class are used as interface in C++.
Interface is useful to standardize API among developers.
A class is abstract if one of its method is pure virtual.
Pure virtual method must be implemented by child class.

Although abstract class can contain non-pure methods
and even attributes, to do so defeat the purpose of
creating interface. Should only declare pure methods
except for the destructor because declaring destructor
pure meaning it has to be implemented in child class.
But explicitly overriding ~AbstractClassB() is illegal
in child class, so counterintuitively, you will need
to provide definition of destructor in a separate
AbstractClassB.cpp file which overcomplicates the matter.
You might just define it in the header.
*/
#ifndef SRC_INHERITANCE_ABSTRACT_CLASS_B_H_
#define SRC_INHERITANCE_ABSTRACT_CLASS_B_H_

namespace cpp_boilerplate {
class AbstractClassB {
 public:  // all interface methods should be public
    
    // all parent class must declare virtual destructor
    // to guard against unintentional calling the
    // parent destructor on child instance.
    virtual ~AbstractClassB() {
        std::cout << "~AbstractClassB" << std::endl;
    }

    // all interface methods must be marked pure (=0)
    // so that the compiler will check they are implemented
    // by child class
    virtual std::string InterfaceMethodB(const std::string& arg) const = 0; 

    // do not declare attributes in interface
};
}  // namespace cpp_boilerplate
#endif  // SRC_INHERITANCE_ABSTRACT_CLASS_B_H_
