/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT

The inheritance tree:
AbstractClassA, AbstractClassB
|_ConcreteClass
    |_ConcreteChildClass

Be warned that multi-level inheritance makes the code
harder to trace and should be avoided as much as possible.
Consider composition rather than inheritance.

While inheriting from multiple abstract classes is allowed,
avoid inheriting from multiple concrete classes as it can
introduce diamond inheritance problem. Consider composition
instead.

for more information, read up on SOLID principles of OOP.

*/
#ifndef SRC_INHERITANCE_CONCRETE_CHILD_CLASS_H_
#define SRC_INHERITANCE_CONCRETE_CHILD_CLASS_H_

#include "concrete_class.h"
namespace cpp_boilerplate {
class ConcreteChildClass : public ConcreteClass {
 public:
    // default constructor
    ConcreteChildClass();
    // parameterized constructors
    explicit ConcreteChildClass(const std::string& arg);
    explicit ConcreteChildClass(const std::string& parent_arg,const std::string& arg);
    // always make destructor virtual
    virtual ~ConcreteChildClass();
    
    // public methods can be accessed by anyone, including child
    std::string ConcreteChildPublicMethod(const std::string& arg) const;

    // override parent method
    // note you can continue mark the method virtual to make
    // it overridable by child class
    virtual std::string ConcreteMethodOverridable(const std::string& arg) const override;
 private:
    // can be same method name as parent
    std::string PrivateMethod(const std::string& arg) const;
    // can same attribute name as parent
    const std::string private_attribute;
};
}  // namespace cpp_boilerplate
#endif  // SRC_INHERITANCE_CONCRETE_CHILD_CLASS_H_
