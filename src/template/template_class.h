/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT

Demo template class
WARNING: supply template definition in header for
both readability and linking error. 
*/
#ifndef SRC_TEMPLATE_TEMPLATE_CLASS_H_
#define SRC_TEMPLATE_TEMPLATE_CLASS_H_

#include <type_traits>  // needed by static_assert
#include <algorithm>    // std::max

#include "operator_overload/operator_overloaded_class.h"

namespace cpp_boilerplate {

// most of the time, typename is interchangeable with class
template <typename T, class S>
class TemplateClass {
    // in case you want to restrict the type of T, use static_assert
    // there are many more type traits you can use than shown here
    // static_assert(std::is_base_of<OperatorOverloadedClass, T>::value, "T must inherit from OperatorOverloadedClass");
 public:
    // parameterized constructor
    explicit TemplateClass(T arg1, S arg2) : 
        private_attribute_(arg1),
        private_attribute2_(arg2) {}
    // always make destructor virtual to guard against memory leak
    virtual ~TemplateClass() {}

    // public method, define function in header only
    // avoid splitting to .cpp else compilation may error
    // under certain configuration
    T PublicMethod(const T& t) const {
        return std::max(private_attribute_, t);
    }
    S PublicMethod2(const S& s) const {
        return std::max(private_attribute2_, s);
    }
 private:
    T private_attribute_;
    S private_attribute2_;
};
}  // namespace cpp_boilerplate

#endif  // SRC_TEMPLATE_TEMPLATE_CLASS_H_
