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

TEST(osfes_05_references, point_class) {
	// Check if the 'Point' class constructor assigns coordinates properly
	for (int i = 0; i < 10; i++) {
		double x = static_cast<double>(rand());
		double y = static_cast<double>(rand());
		osfes::Point p(x,y);
		EXPECT_DOUBLE_EQ(p.x, x) << "x coordinate in 'Point' class not assigned properly";
		EXPECT_DOUBLE_EQ(p.y, y) << "y coordinate in 'Point' class not assigned properly";
	}
}

TEST(osfes_05_references, rectangle_class) {
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

TEST(osfes_05_references, plane_class) {
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

TEST(osfes_05_references, association) {
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
