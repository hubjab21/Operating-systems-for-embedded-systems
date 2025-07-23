#include <gtest/gtest.h>
#include <cstdlib>

#include "namespaces.hpp"
// test for #include guard by including the header file again
#include "namespaces.hpp"

// Declare some objects using nested namespaces
osfes::nested::MyNestedClass obj1;
osfes::nested::deeply::MyDeeplyNestedClass obj2;


TEST(osfes_02_namespaces, namespaces) {
    // It this builds, you passed
    SUCCEED();
}
