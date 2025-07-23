#pragma once

#include "shape.hpp"

namespace osfes {
    class Rectangle : public Shape {
      private:
        double width{};
        double height{};

      public:
        Rectangle(double x, double y, double w, double h, Plane& p, Texture* t = nullptr) : Shape{x, y, p, t}, width{w}, height{h} {
        }

        Rectangle(const Rectangle& r) : Shape{r.getX(), r.getY(), r.getPlane(), r.getTexture()}, width{r.width}, height{r.height} {
        }

        ~Rectangle() = default;

        double getWidth() const {
            return width;
        }

        double getHeight() const {
            return height;
        }

        virtual double getArea() const {
            return width * height;
        }

        virtual std::string getName() const {
            return "Rectangle";
        }
    };
} // namespace osfes