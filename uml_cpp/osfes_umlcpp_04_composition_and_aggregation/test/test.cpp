#include <gtest/gtest.h>
#include <cstdlib>

#include "rectangle.hpp"
#include "point.hpp"
#include "texture.hpp"
// test for #include guard by including the header files again
#include "rectangle.hpp"
#include "point.hpp"
#include "texture.hpp"

TEST(osfes_04_composition_and_aggregation, point_class) {
	// Check if the 'Point' class constructor assigns coordinates properly
	for (int i = 0; i < 10; i++) {
		double x = static_cast<double>(rand());
		double y = static_cast<double>(rand());
		osfes::Point p(x,y);
		EXPECT_DOUBLE_EQ(p.x, x) << "x coordinate in 'Point' class not assigned properly";
		EXPECT_DOUBLE_EQ(p.y, y) << "y coordinate in 'Point' class not assigned properly";
	}
}

TEST(osfes_04_composition_and_aggregation, rectangle_class_constructors) {
	// Construct rectangle with default texture
	osfes::Rectangle r(0, 0, 10, 10);
	// Check that texture is a nullptr
	EXPECT_EQ(r.getTexture(), nullptr) << "default texture in 'Rectangle' class should be nullptr";

	// Construct rectangle with explicit texture
	osfes::Texture t;
	osfes::Rectangle r2(0, 0, 10, 10, &t);
	EXPECT_EQ(r2.getTexture(), &t) << "explicitly provided texture not set in 'Rectangle' class constructor";
}

TEST(osfes_04_composition_and_aggregation, rectangle_class) {
	// Check if the 'Rectangle' class constructor assigns coordinates and dimensions properly
	for (int i = 0; i < 10; i++) {
		double x = static_cast<double>(rand());
		double y = static_cast<double>(rand());
		double w = static_cast<double>(rand());
		double h = static_cast<double>(rand());
		osfes::Rectangle r(x,y,w,h);
		// Check dimensions
		EXPECT_DOUBLE_EQ(r.getWidth(), w) << "width in 'Rectangle' class not assigned properly or getter not working";
		EXPECT_DOUBLE_EQ(r.getHeight(), h) << "height in 'Rectangle' class not assigned properly or getter not working";
		// Check composition
		EXPECT_DOUBLE_EQ(r.getX(), x) << "x coordinate in 'Rectangle' class not assigned properly or getter not working";
		EXPECT_DOUBLE_EQ(r.getY(), y) << "y coordinate in 'Rectangle' class not assigned properly or getter not working";
		// Check texture setter and getter
		osfes::Texture t;
		r.setTexture(&t);
		EXPECT_EQ(r.getTexture(), &t) << "texture in 'Rectangle' class not assigned properly or getter not working";
		osfes::Texture t2;
		r.setTexture(&t2);
		EXPECT_EQ(r.getTexture(), &t2) << "texture in 'Rectangle' class not assigned properly or getter not working";
	}
}
