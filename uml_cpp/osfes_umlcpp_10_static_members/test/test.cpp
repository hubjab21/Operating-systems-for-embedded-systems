#include <gtest/gtest.h>
#include <cstdlib>

#include "my_countable_class.hpp"

// Create 3 objects of class 'MyCountableClass'
osfes::MyCountableClass myCC0, myCC1, myCC2;

TEST( osfes_10_static_members, static_counter ) {
	// Check how many objects were created so far
	EXPECT_EQ(osfes::MyCountableClass::getCount(), 3);
}

TEST( osfes_10_static_members, get_my_number ) {
	// While it's a bit fuzzy in the C++ standard, I guess we can assume here
	// that the order of variable initialization will be maintained, so we can check:
	EXPECT_EQ(myCC0.getMyNumber(), 0);
	EXPECT_EQ(myCC1.getMyNumber(), 1);
	EXPECT_EQ(myCC2.getMyNumber(), 2);
	// Let's add another object by constructing it dynamically, and check its number
	osfes::MyCountableClass* pMyCC3= new osfes::MyCountableClass();
	EXPECT_EQ(pMyCC3->getMyNumber(), 3);
	delete pMyCC3;
}

