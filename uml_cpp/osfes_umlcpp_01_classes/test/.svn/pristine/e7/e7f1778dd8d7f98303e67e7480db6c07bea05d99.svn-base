#include "my_class.hpp"

#include <gtest/gtest.h>

#include <cstdlib>

// test for #include guard by including the header file again
#include "my_class.hpp"

using namespace std;


template<typename T>
concept is_public = requires(T t) { t.privateAttribute = 4; };

TEST(osfes_01_classes, default_constructor) {
    // Declare an object of class 'MyClass' to check if it has a default constructor
    MyClass obj;
    SUCCEED();
}

TEST(osfes_01_classes, public_attribute) {
    MyClass obj;
    // Set the public data member to a random value to check if it is accessible
    int expected        = rand();
    obj.publicAttribute = expected;
    EXPECT_EQ(expected, obj.publicAttribute);
}

TEST(osfes_01_classes, private_attribute) {
    // Check if the 'privateAttribute' is in fact private
    EXPECT_FALSE(is_public<MyClass>) << "privateAttribute is declared public";

    // Check the setter and getter for the 'privateAttribute'
    MyClass obj;
    int     expected = rand();
    obj.setPrivateAttribute(expected);
    EXPECT_EQ(expected, obj.getPrivateAttribute()) << "setter or getter for the privateAttribute is not working correctly";
}

TEST(osfes_01_classes, multiply) {
    MyClass obj;

    // Check if multiply() is working by making several tries with random values
    for (auto i = 0; i != 10; ++i) {
        int  a        = rand();
        int  b        = rand();
        auto expected = static_cast<long>(a) * b;
        obj.setPrivateAttribute(a);
        obj.publicAttribute = b;

        EXPECT_EQ(expected, obj.multiply()) << "multiply() returned unexpected result";
    }

    // Check if multiply(int) is working by making several tries with random values
    for (int i = 0; i < 10; i++) {
        int  a        = rand();
        int  b        = rand();
        auto expected = static_cast<long>(a) * b;
        obj.setPrivateAttribute(a);
        EXPECT_EQ(expected, obj.multiply(b)) << "multiply(int) returned unexpected result";
    }
}