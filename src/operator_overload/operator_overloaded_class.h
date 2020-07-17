/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT

Demonstrates how to overload common operators
However, avoid operator overload as much as possible
If you have to, make sure its meaning is as expected
*/
#ifndef SRC_OPERATOR_OVERLOAD_OPERATOR_OVERLOADED_CLASS_H_
#define SRC_OPERATOR_OVERLOAD_OPERATOR_OVERLOADED_CLASS_H_

#include <tuple>  // needed by std::tie

namespace cpp_boilerplate {
class OperatorOverloadedClass {
 public:
    OperatorOverloadedClass(int x, int y) : x_(x), y_(y) {}
    virtual ~OperatorOverloadedClass() {}

    // the two most important comparators are == and <
    // the rest can be derived easily from these two
    // also sort relies on "<"

    // Note "friend" is a must here to access private attributes
    // "inline" is optional
    inline friend bool operator== (
        const OperatorOverloadedClass& l, const OperatorOverloadedClass& r) {
        // create tuples on attributes' references using std::tie
        // then use existing tuple comparator easily
        // note std::make_tuple will copy values so not as efficient
        return std::tie(l.x_, l.y_) == std::tie(r.x_, r.y_);
    }
    inline friend bool operator< (
        const OperatorOverloadedClass& l, const OperatorOverloadedClass& r) {
        // create tuples on attributes' references using std::tie
        // note std::make_tuple will copy values
        return std::tie(l.x_, l.y_) < std::tie(r.x_, r.y_);
    }
    inline friend bool operator!= (
        const OperatorOverloadedClass& l, const OperatorOverloadedClass& r) {
        return !(l == r);
    }
    inline friend bool operator> (
        const OperatorOverloadedClass& l, const OperatorOverloadedClass& r) {
        return r < l;
    }
    inline friend bool operator<= (
        const OperatorOverloadedClass& l, const OperatorOverloadedClass& r) {
        return !(l > r);
    }
    inline friend bool operator>= (
        const OperatorOverloadedClass& l, const OperatorOverloadedClass& r) {
        return !(l < r);
    }

 private:
    int x_;
    int y_;
};
}  // namespace cpp_boilerplate

#endif  // SRC_OPERATOR_OVERLOAD_OPERATOR_OVERLOADED_CLASS_H_
