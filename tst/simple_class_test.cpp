/*
Copyright: 2020 liyinnbw
author: liyinnbw
licence: MIT
*/
#include <iostream>

#include "gtest/gtest.h"
#include "simple_class.h"

namespace cpp_boilerplate{
TEST(SimpleClass, ClassMethod) {
    SimpleClass simple_class_default;
    EXPECT_EQ(simple_class_default.class_attribute, 1);
    SimpleClass simple_class_param(3);
    EXPECT_EQ(simple_class_default.class_attribute, 2);  
    EXPECT_EQ(simple_class_default.class_attribute, 
        simple_class_param.class_attribute);
    simple_class_default.ClassMethod();  
    EXPECT_EQ(simple_class_default.class_attribute, 3);
    EXPECT_EQ(simple_class_default.class_attribute, 
        simple_class_param.class_attribute);
}

TEST(SimpleClass, Constructor) {
    SimpleClass simple_class_default;
    EXPECT_EQ(simple_class_default.GetPrivateAttribute(), 0);
    EXPECT_EQ(simple_class_default.GetPrivateAttribute(), 
        simple_class_default.kPublicAttribute);

    SimpleClass simple_class_param(3);
    EXPECT_EQ(simple_class_param.GetPrivateAttribute(), 3);
    EXPECT_EQ(simple_class_default.GetPrivateAttribute(), 
        simple_class_default.kPublicAttribute);
}

TEST(SimpleClass, PublicMethod) {
    SimpleClass simple_class_default;
    EXPECT_EQ(simple_class_default.PublicMethod(1, "result"), "result:1");
    EXPECT_EQ(simple_class_default.PublicMethod(1, "result"), "result:2");
    SimpleClass simple_class_default2;
    EXPECT_EQ(simple_class_default2.PublicMethod(1, "result"), "result:3");
}

// this test case will be compiled as a class called
// SimpleClass_PrivateMethod_Test
// In order to test private method, we can set this
// class a friend of the class under test
// It is crucial that this test case bust be enclosed
// in the same namespace as the class under test
TEST(SimpleClass, PrivateMethod) {
    SimpleClass simple_class_default;
    EXPECT_EQ(simple_class_default.PrivateMethod(1), false);
    EXPECT_EQ(simple_class_default.PrivateMethod(2), true);
}
}
