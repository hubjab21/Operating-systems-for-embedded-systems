#include <gtest/gtest.h>
#include <cstdlib>

#include "rectangle.hpp"
#include "point.hpp"
#include "texture.hpp"
#include "plane.hpp"
// test for #include guard by including the header files again
#include "rectangle.hpp"
#include "point.hpp"
#include "texture.hpp"
#include "plane.hpp"

TEST(osfes_06_copy_constructor, point_class) {
	// Check if the 'Point' class constructor assigns coordinates properly
	for (int i = 0; i < 10; i++) {
		double x = static_cast<double>(rand());
		double y = static_cast<double>(rand());
		osfes::Point p(x,y);
		EXPECT_DOUBLE_EQ(p.x, x) << "x coordinate in 'Point' class not assigned properly";
		EXPECT_DOUBLE_EQ(p.y, y) << "y coordinate in 'Point' class not assigned properly";
	}
}

TEST(osfes_06_copy_constructor, rectangle_class) {
	// Check if the 'Rectangle' class constructor assigns coordinates and dimensions properly
	for (int i = 0; i < 10; i++) {
		double x = static_cast<double>(rand());
		double y = static_cast<double>(rand());
		double w = static_cast<double>(rand());
		double h = static_cast<double>(rand());
		osfes::Plane p(w,h);
		osfes::Rectangle r(x,y,w,h,p);
		// Check dimensions
		EXPECT_DOUBLE_EQ(r.getWidth(), w) << "width in 'Rectangle' class not assigned properly or getter not working";
		EXPECT_DOUBLE_EQ(r.getHeight(), h) << "height in 'Rectangle' class not assigned properly or getter not working";
		// Check composition
		EXPECT_DOUBLE_EQ(r.getX(), x) << "x coordinate in 'Rectangle' class not assigned properly or getter not working";
		EXPECT_DOUBLE_EQ(r.getY(), y) << "y coordinate in 'Rectangle' class not assigned properly or getter not working";
		// Check aggregation
		osfes::Texture t;
		r.setTexture(&t);
		EXPECT_EQ(r.getTexture(), &t) << "texture in 'Rectangle' class not assigned properly or getter not working";
	}
}

TEST(osfes_06_copy_constructor, plane_class) {
	// Check if the 'Plane' class constructor assigns proper dimensions
	for (int i = 0; i < 10; i++) {
		// chose random plane dimensions
		double w = static_cast<double>(rand());
		double h = static_cast<double>(rand());
		osfes::Plane p(w,h);
		EXPECT_DOUBLE_EQ(p.getWidth(), w) << "width in 'Plane' class not assigned properly or getter not working";
		EXPECT_DOUBLE_EQ(p.getHeight(), h) << "height in 'Plane' class not assigned properly or getter not working";
	}
}

TEST(osfes_06_copy_constructor, association) {
	// Check if the 'Rectangle' constructor makes the association with the 'Plane' class object
	for (int i = 0; i < 10; i++) {
		// chose random plane dimensions
		double pw = static_cast<double>(rand());
		double ph = static_cast<double>(rand());
		osfes::Plane p(pw,ph);
		// chose random rectangle dimensions
		double rx = static_cast<double>(rand());
		double ry = static_cast<double>(rand());
		double rw = static_cast<double>(rand());
		double rh = static_cast<double>(rand());
		osfes::Rectangle r(rx, ry, rw, rh, p);
		// check association
		EXPECT_DOUBLE_EQ(r.getPlane().getWidth(), pw) << "unexpected 'Plane' object width";
		EXPECT_DOUBLE_EQ(r.getPlane().getHeight(), ph) << "unexpected 'Plane' object height";
	}
}

TEST(osfes_06_copy_constructor, point_copy_constructor) {
	for (int i = 0; i < 10; i++) {
		// Make a random point
		double x = static_cast<double>(rand());
		double y = static_cast<double>(rand());
		osfes::Point p(x,y);
		// Make a copy
		osfes::Point p2(p);
		// Check the copy
		EXPECT_DOUBLE_EQ(p2.x, x) << "unexpected x coordinate in a copy of a 'Point' object";
		EXPECT_DOUBLE_EQ(p2.y, y) << "unexpected y coordinate in a copy of a 'Point' object";
	}
}

TEST(osfes_06_copy_constructor, point_copy_constructor_const) {
	for (int i = 0; i < 10; i++) {
		// Make a random const point
		double x = static_cast<double>(rand());
		double y = static_cast<double>(rand());
		const osfes::Point p(x,y);
		// Make a copy
		osfes::Point p2(p);
		// Check the copy
		EXPECT_DOUBLE_EQ(p2.x, x) << "unexpected x coordinate in a copy of a const 'Point' object";
		EXPECT_DOUBLE_EQ(p2.y, y) << "unexpected y coordinate in a copy of a const 'Point' object";
	}
}

TEST(osfes_06_copy_constructor, plane_copy_constructor) {
	for (int i = 0; i < 10; i++) {
		// Make a random plane
		double w = static_cast<double>(rand());
		double h = static_cast<double>(rand());
		osfes::Plane p(w,h);
		// Make a copy
		osfes::Plane p2(p);
		// Check the copy
		EXPECT_DOUBLE_EQ(p2.getWidth(), w) << "unexpected width in a copy of a 'Plane' object";
		EXPECT_DOUBLE_EQ(p2.getHeight(), h) << "unexpected height in a copy of a 'Plane' object";
	}
}

TEST(osfes_06_copy_constructor, plane_copy_constructor_const) {
	for (int i = 0; i < 10; i++) {
		// Make a random const plane
		double w = static_cast<double>(rand());
		double h = static_cast<double>(rand());
		const osfes::Plane p(w,h);
		// Make a copy
		osfes::Plane p2(p);
		// Check the copy
		EXPECT_DOUBLE_EQ(p2.getWidth(), w) << "unexpected width in a copy of a const 'Plane' object";
		EXPECT_DOUBLE_EQ(p2.getHeight(), h) << "unexpected height in a copy of a const 'Plane' object";
	}
}

TEST(osfes_06_copy_constructor, rectangle_copy_constructor) {
	for (int i = 0; i < 10; i++) {
		// Make a random rectangle
		double pw = static_cast<double>(rand());
		double ph = static_cast<double>(rand());
		double rx = static_cast<double>(rand());
		double ry = static_cast<double>(rand());
		double rw = static_cast<double>(rand());
		double rh = static_cast<double>(rand());
		osfes::Plane p(pw,ph);
		osfes::Rectangle r(rx, ry, rw, rh, p);
		osfes::Texture t;
		r.setTexture(&t);

		// Make the copy
		osfes::Rectangle r2(r);

		// Check the copy
		EXPECT_DOUBLE_EQ(r2.getX(), rx) << "unexpected x coordinate in a copy of a 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getY(), ry) << "unexpected y coordinate in a copy of a 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getWidth(), rw) << "unexpected width in a copy of a 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getHeight(), rh) << "unexpected height in a copy of a 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getPlane().getWidth(), pw) << "unexpected plane width in a copy of a 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getPlane().getHeight(), ph) << "unexpected plane height in a copy of a 'Rectangle' object";
		EXPECT_EQ(r2.getTexture(), &t) << "unexpected texture in a copy of a 'Rectangle' object";
	}
}

TEST(osfes_06_copy_constructor, rectangle_copy_constructor_const) {
	for (int i = 0; i < 10; i++) {
		// Make a random const rectangle
		double pw = static_cast<double>(rand());
		double ph = static_cast<double>(rand());
		double rx = static_cast<double>(rand());
		double ry = static_cast<double>(rand());
		double rw = static_cast<double>(rand());
		double rh = static_cast<double>(rand());
		osfes::Plane p(pw,ph);
		const osfes::Rectangle r(rx, ry, rw, rh, p);
		osfes::Texture t;

		// Make the copy
		osfes::Rectangle r2(r);

		// Check the copy
		EXPECT_DOUBLE_EQ(r2.getX(), rx) << "unexpected x coordinate in a copy of a const 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getY(), ry) << "unexpected y coordinate in a copy of a const 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getWidth(), rw) << "unexpected width in a copy of a const 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getHeight(), rh) << "unexpected height in a copy of a const 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getPlane().getWidth(), pw) << "unexpected plane width in a copy of a const 'Rectangle' object";
		EXPECT_DOUBLE_EQ(r2.getPlane().getHeight(), ph) << "unexpected plane height in a copy of a const 'Rectangle' object";
	}
}
