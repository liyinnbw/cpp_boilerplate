/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT

The inheritance tree:
AbstractClassA, AbstractClassB
|_ConcreteClass

*/
#ifndef SRC_INHERITANCE_CONCRETE_CLASS_H_
#define SRC_INHERITANCE_CONCRETE_CLASS_H_

#include "abstract_class_a.h"
#include "abstract_class_b.h"

namespace cpp_boilerplate {
class ConcreteClass : public AbstractClassA,
                      public AbstractClassB {  // avoid private inheritance
                                               // which can be replaced by
                                               // composition pattern
 public:  // accessible by anyone, including child
    // default constructor
    ConcreteClass();
    // parameterized constructor
    explicit ConcreteClass(const std::string& arg);
    // always make destructor virtual
    virtual ~ConcreteClass();
    
    // override interface methods
    std::string InterfaceMethodA(const std::string& arg) const override;
    std::string InterfaceMethodB(const std::string& arg) const override;

    // public method
    std::string ConcretePublicMethod(const std::string& arg) const;

    // method which can be overriden by child
    // can either be public or protected
    virtual std::string ConcreteMethodOverridable(const std::string& arg) const;

 protected:  // accessible by self and child, use rarely
    std::string ConcreteProtectedMethod(const std::string& arg) const;

 private:   // accessible by self only
    // same method name is allowed in child
    std::string PrivateMethod(const std::string& arg) const;
    // same attribute name is allowed in child
    const std::string private_attribute;
};
}  // namespace cpp_boilerplate
#endif  // SRC_INHERITANCE_CONCRETE_CLASS_H_
