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
#include "template/template_class.h"
#include "operator_overload/operator_overloaded_class.h"


namespace cpp_boilerplate{
TEST(TemplateClass, OperatorOverloadedClass) {
    OperatorOverloadedClass a(1,0);
    OperatorOverloadedClass b(1,1);
    OperatorOverloadedClass c(-1,0);
    TemplateClass<OperatorOverloadedClass, int> template_class(a, 0);
    EXPECT_EQ(template_class.PublicMethod(b), b);
    EXPECT_EQ(template_class.PublicMethod(c), a);
}
TEST(TemplateClass, Integer) {
    int a = 1;
    int b = 2;
    int c = -1;
    float af = 1;
    float bf = 2;
    float cf = -1;
    TemplateClass<int, float> template_class(a, af);
    EXPECT_EQ(template_class.PublicMethod(b), b);
    EXPECT_EQ(template_class.PublicMethod(c), a);
    EXPECT_EQ(template_class.PublicMethod2(bf), bf);
    EXPECT_EQ(template_class.PublicMethod2(cf), af);
}

}
