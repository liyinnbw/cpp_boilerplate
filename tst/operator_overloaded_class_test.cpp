/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#include "gtest/gtest.h"
#include "operator_overload/operator_overloaded_class.h"

namespace cpp_boilerplate{
TEST(OperatorOverloadedClass, Comparators) {
    OperatorOverloadedClass a(1,0);
    OperatorOverloadedClass b(2,0);
    OperatorOverloadedClass c(1,1);
    OperatorOverloadedClass d(1,1);

    EXPECT_EQ(c, d);
    EXPECT_EQ(c == d, true);
    EXPECT_EQ(c != d, false);
    EXPECT_EQ(c <= d, true);
    EXPECT_EQ(c >= d, true);
    EXPECT_EQ(c < d, false);
    EXPECT_EQ(c > d, false);

    EXPECT_EQ(d == c, true);
    EXPECT_EQ(d != c, false);
    EXPECT_EQ(d <= c, true);
    EXPECT_EQ(d >= c, true);
    EXPECT_EQ(d < c, false);
    EXPECT_EQ(d > c, false);

    EXPECT_EQ(a == b, false);
    EXPECT_EQ(a != b, true);
    EXPECT_EQ(a <= b, true);
    EXPECT_EQ(a >= b, false);
    EXPECT_EQ(a < b, true);
    EXPECT_EQ(a > b, false);

    EXPECT_EQ(b == a, false);
    EXPECT_EQ(b != a, true);
    EXPECT_EQ(b <= a, false);
    EXPECT_EQ(b >= a, true);
    EXPECT_EQ(b < a, false);
    EXPECT_EQ(b > a, true);

    EXPECT_EQ(a == c, false);
    EXPECT_EQ(a != c, true);
    EXPECT_EQ(a <= c, true);
    EXPECT_EQ(a >= c, false);
    EXPECT_EQ(a < c, true);
    EXPECT_EQ(a > c, false);

    EXPECT_EQ(c == a, false);
    EXPECT_EQ(c != a, true);
    EXPECT_EQ(c <= a, false);
    EXPECT_EQ(c >= a, true);
    EXPECT_EQ(c < a, false);
    EXPECT_EQ(c > a, true);

    EXPECT_EQ(b == c, false);
    EXPECT_EQ(b != c, true);
    EXPECT_EQ(b <= c, false);
    EXPECT_EQ(b >= c, true);
    EXPECT_EQ(b < c, false);
    EXPECT_EQ(b > c, true);

    EXPECT_EQ(c == b, false);
    EXPECT_EQ(c != b, true);
    EXPECT_EQ(c <= b, true);
    EXPECT_EQ(c >= b, false);
    EXPECT_EQ(c < b, true);
    EXPECT_EQ(c > b, false);

}

TEST(SimpleClass, Tuple) {
    OperatorOverloadedClass a(1,0);
    OperatorOverloadedClass b(2,0);
    OperatorOverloadedClass c(1,1);
    OperatorOverloadedClass d(1,1);

    EXPECT_EQ(std::tie(a, c) < std::tie(a, b), true);
    EXPECT_EQ(std::tie(b, a) < std::tie(b, c), true);
}

TEST(SimpleClass, Sort) {
    std::vector<OperatorOverloadedClass> vec;
    vec.emplace_back(1, 0);
    vec.emplace_back(2, 0);
    vec.emplace_back(1, 1);
    vec.emplace_back(1, 1);
    std::sort(vec.begin(), vec.end());
    std::vector<OperatorOverloadedClass> vec_expected;
    vec_expected.emplace_back(1, 0);
    vec_expected.emplace_back(1, 1);
    vec_expected.emplace_back(1, 1);
    vec_expected.emplace_back(2, 0);
    EXPECT_EQ(vec, vec_expected);
}
}
