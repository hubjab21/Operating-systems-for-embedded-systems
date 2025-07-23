#include <gtest/gtest.h>
#include <cstdlib>

#include "rectangle.hpp"
// test for #include guard by including the header file again
#include "rectangle.hpp"

using namespace std;

TEST(osfes_03_constructors, constructor) {
	
	for (int i = 0; i < 10; i++) {
		// Choose random dimensions
		double w = static_cast<double>(rand());
		double h = static_cast<double>(rand());
		// Create an object of class 'Rectangle'
		osfes::Rectangle r(w, h);
		// Check if the constructor has assigned the expected dimensions
		EXPECT_DOUBLE_EQ(r.getWidth(), w) << "getWidth returned unexpected value";
		EXPECT_DOUBLE_EQ(r.getHeight(), h) << "getHeight returned unexpected value";
	}
}
