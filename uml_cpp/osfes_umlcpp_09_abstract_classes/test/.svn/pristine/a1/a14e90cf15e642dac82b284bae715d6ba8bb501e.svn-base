#include <gtest/gtest.h>
#include <cstdlib>

#include "point.hpp"
#include "texture.hpp"
#include "plane.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "circle.hpp"
// test for #include guard by including the header files again
#include "point.hpp"
#include "texture.hpp"
#include "plane.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "circle.hpp"

#include <math.h>
// on some platforms M_PI is already defined in math.h
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

TEST(osfes_09_abstract_classes, point_class) {
	// Check if the 'Point' class constructor assigns coordinates properly
	for (int i = 0; i < 10; i++) {
		double x = static_cast<double>(rand());
		double y = static_cast<double>(rand());
		osfes::Point p(x,y);
		EXPECT_DOUBLE_EQ(p.x, x) << "x coordinate in 'Point' class not assigned properly";
		EXPECT_DOUBLE_EQ(p.y, y) << "y coordinate in 'Point' class not assigned properly";
	}
}

TEST(osfes_09_abstract_classes, rectangle_class) {
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

TEST(osfes_09_abstract_classes, plane_class) {
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

TEST(osfes_09_abstract_classes, association) {
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

TEST(osfes_09_abstract_classes, point_copy_constructor) {
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

TEST(osfes_09_abstract_classes, point_copy_constructor_const) {
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

TEST(osfes_09_abstract_classes, plane_copy_constructor) {
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

TEST(osfes_09_abstract_classes, plane_copy_constructor_const) {
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

TEST(osfes_09_abstract_classes, rectangle_copy_constructor) {
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

TEST(osfes_09_abstract_classes, rectangle_copy_constructor_const) {
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

TEST(osfes_09_abstract_classes, square_constructors) {
	for (int i = 0; i < 10; i++) {
		// Chose random plane dimensions
		double pw = static_cast<double>(rand());
		double ph = static_cast<double>(rand());
		// Chose random square dimensions
		double sx = static_cast<double>(rand());
		double sy = static_cast<double>(rand());
		double sw = static_cast<double>(rand());

		// Construct a square object
		osfes::Plane p(pw,ph);
		const osfes::Square s(sx, sy, sw, p);

		// Check the object
		EXPECT_DOUBLE_EQ(s.getX(), sx) << "Unexpected x coordinate of a constructed 'Square' class object";
		EXPECT_DOUBLE_EQ(s.getY(), sy) << "Unexpected y coordinate of a constructed 'Square' class object";
		EXPECT_DOUBLE_EQ(s.getWidth(), sw) << "Unexpected width of a constructed 'Square' class object";
		EXPECT_DOUBLE_EQ(s.getHeight(), sw) << "Unexpected height of a constructed 'Square' class object";
		EXPECT_DOUBLE_EQ(s.getPlane().getWidth(), pw) << "Unexpected plane width of a constructed 'Square' class object";
		EXPECT_DOUBLE_EQ(s.getPlane().getHeight(), ph) << "Unexpected plane height of a constructed 'Square' class object";

		// Make a copy
		osfes::Square s2(s);

		// Check the copy
		EXPECT_DOUBLE_EQ(s2.getX(), sx) << "Unexpected x coordinate of a 'Square' class object copy";
		EXPECT_DOUBLE_EQ(s2.getY(), sy) << "Unexpected y coordinate of a 'Square' class object copy";
		EXPECT_DOUBLE_EQ(s2.getWidth(), sw) << "Unexpected width of a 'Square' class object copy";
		EXPECT_DOUBLE_EQ(s2.getHeight(), sw) << "Unexpected height of a 'Square' class object copy";
		EXPECT_DOUBLE_EQ(s2.getPlane().getWidth(), pw) << "Unexpected plane width of a 'Square' class object copy";
		EXPECT_DOUBLE_EQ(s2.getPlane().getHeight(), ph) << "Unexpected plane height of a 'Square' class object copy";
	}
}

TEST(osfes_09_abstract_classes, square_inheritance) {
	// Chose random plane dimensions
	double pw = static_cast<double>(rand());
	double ph = static_cast<double>(rand());
	// Chose random rectangle dimensions
	double sx = static_cast<double>(rand());
	double sy = static_cast<double>(rand());
	double sw = static_cast<double>(rand());

	// Construct a new Square object using new operator
	osfes::Plane p(pw,ph);
	osfes::Square* s = new osfes::Square(sx,sy,sw,p);

	// Check if Square object can be dynamically casted to Rectangle class type, which proves inheritance
	osfes::Rectangle* r = dynamic_cast<osfes::Rectangle*>(s);
	EXPECT_NE(r, nullptr);

	// Check if parent interface works on a child
	EXPECT_DOUBLE_EQ(s->getX(), sx);
	EXPECT_DOUBLE_EQ(s->getY(), sy);
	EXPECT_DOUBLE_EQ(s->getWidth(), sw);
	EXPECT_DOUBLE_EQ(s->getHeight(), sw);
	EXPECT_DOUBLE_EQ(s->getPlane().getWidth(), pw);
	EXPECT_DOUBLE_EQ(s->getPlane().getHeight(), ph);

	// Check if parent interface works in base class
	if (r) {
		// Check the object
		EXPECT_DOUBLE_EQ(r->getX(), sx);
		EXPECT_DOUBLE_EQ(r->getY(), sy);
		EXPECT_DOUBLE_EQ(r->getWidth(), sw);
		EXPECT_DOUBLE_EQ(r->getHeight(), sw);
		EXPECT_DOUBLE_EQ(r->getPlane().getWidth(), pw);
		EXPECT_DOUBLE_EQ(r->getPlane().getHeight(), ph);
	}

	// Check if Square inherits from Shape
	osfes::Shape* shape = dynamic_cast<osfes::Shape*>(s);
	EXPECT_NE(shape, nullptr);

	delete s;
}

TEST(osfes_09_abstract_classes, circle_inheritance) {
	// Create a Plane class object
	osfes::Plane p(10.0, 10.0);
	// Choose random circle radius
	double radius = static_cast<double>(rand());
	// Construct a new Circle object using new operator
	osfes::Circle* circle = new osfes::Circle(0.0, 0.0, radius, p);
	// Check if Circle inherits from Shape
	osfes::Shape* shape = dynamic_cast<osfes::Shape*>(circle);
	EXPECT_NE(shape, nullptr);
	delete circle;
}

TEST(osfes_09_abstract_classes, virtual_method_getname) {
	// Construct a Plane class object
	osfes::Plane p(10.0, 10.0);
	// Construct a Rectangle class object
	osfes::Rectangle r(0.0, 0.0, 10.0, 20.0, p);
	// Construct a Square class object
	osfes::Square s(0.0, 0.0, 30.0, p);
	// Construct a Circle class object
	osfes::Circle c(0.0, 0.0, 40.0, p);
	// Test basic method calls
	EXPECT_EQ(r.getName(), "Rectangle") << "unexpected name of the 'Rectangle' class object";
	EXPECT_EQ(s.getName(), "Square")  << "unexpected name of the 'Square' class object";
	EXPECT_EQ(c.getName(), "Circle")  << "unexpected name of the 'Circle' class object";
	// Test if the method is really polymorhpic
	osfes::Rectangle& sr = dynamic_cast<osfes::Rectangle&>(s);
	EXPECT_EQ(sr.getName(), "Square") << "unexpected name of the 'Square' class object dynamically casted to 'Rectangle'";
}

TEST(osfes_09_abstract_classes, virtual_method_getarea) {
	double a = static_cast<double>(rand());
	double b = static_cast<double>(rand());
	double c = static_cast<double>(rand());
	double d = static_cast<double>(rand());
	// declare a Plane class object
	osfes::Plane p(10.0, 10.0);
	// declare a Rectangle class object
	osfes::Rectangle rect(0.0, 0.0, a, b, p);
	// declare a Square class object
	osfes::Square square(0.0, 0.0, c, p);
	// declare a Circle class object
	osfes::Circle circle(0.0, 0.0, d, p);

	EXPECT_DOUBLE_EQ(rect.getArea(), a*b) << "unexpected area returned by the 'Rectangle' object";
	EXPECT_DOUBLE_EQ(square.getArea(), c*c) << "unexpected area returned by the 'Square' object";
	EXPECT_DOUBLE_EQ(circle.getArea(), d*d*M_PI) << "unexpected area returned by the 'Circle' object";
}

