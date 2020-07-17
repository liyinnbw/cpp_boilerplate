/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT
*/
#include <iostream>
#include <memory>

#include "simple_class.h"
#include "inheritance/concrete_class.h"
#include "inheritance/concrete_child_class.h"

int main(int argc, char **argv) {
    using cpp_boilerplate::SimpleClass;
    using cpp_boilerplate::AbstractClassA;
    using cpp_boilerplate::AbstractClassB;
    using cpp_boilerplate::ConcreteClass;
    using cpp_boilerplate::ConcreteChildClass;

    std::cout << "=== Simple Class ===" <<std::endl;
    SimpleClass simple_class_default;
    SimpleClass simple_class_paramed(3);
    std::cout << simple_class_default.GetPrivateAttribute() << std::endl;
    std::cout << simple_class_paramed.GetPrivateAttribute() << std::endl;

    std::cout << "=== Concrete Class ===" <<std::endl;
    std::unique_ptr<ConcreteClass> concrete_class 
        = std::make_unique<ConcreteClass>();
    concrete_class->InterfaceMethodA("");
    concrete_class->InterfaceMethodB("");
    concrete_class->ConcretePublicMethod("");
    concrete_class->ConcreteMethodOverridable("");
    concrete_class.reset();

    std::cout << "=== Concrete Child Class ===" <<std::endl;
    std::unique_ptr<ConcreteChildClass> concrete_child_class 
        = std::make_unique<ConcreteChildClass>("Parent","Child");
    concrete_child_class->InterfaceMethodA("");
    concrete_child_class->InterfaceMethodB("");
    concrete_child_class->ConcretePublicMethod("");
    concrete_child_class->ConcreteChildPublicMethod("");
    concrete_child_class->ConcreteMethodOverridable("");
    concrete_child_class.reset();

    std::cout << "=== Abstract Cast ===" <<std::endl;
    // AbstractClassA must has a virtual destructor
    // so that when deleting object class_a, the
    // ConcreteClass destructor is called first
    std::unique_ptr<AbstractClassA> class_a 
        = std::make_unique<ConcreteClass>("Concrete");
    // note you can't call InterfaceMethodB
    class_a->InterfaceMethodA("");
    class_a.reset();

    std::unique_ptr<AbstractClassB> class_b
        = std::make_unique<ConcreteChildClass>("ConcreteChild");
    // note you can't call InterfaceMethodA
    class_b->InterfaceMethodB("");
    class_b.reset();

    
    
    return 0;
}
