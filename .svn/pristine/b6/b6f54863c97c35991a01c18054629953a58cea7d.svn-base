#pragma once

#include "shape.hpp"

#include <math.h>


namespace osfes {
    class Circle : public Shape {
      private:
        double radius;

      public:
        Circle(double x, double y, double r, Plane& p, Texture* t = nullptr) : Shape{x, y, p, t}, radius{r} {
        }

        Circle(Circle& c) : Shape{c.getX(), c.getY(), c.getPlane(), c.getTexture()}, radius{c.radius} {
        }

        ~Circle() = default;

        double getRadius() const {
            return radius;
        }

        virtual double getArea() const {
            return M_PI * radius * radius;
        }

        virtual std::string getName() const {
            return "Circle";
        }
    };
} // namespace osfes