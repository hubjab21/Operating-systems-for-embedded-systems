#pragma once

#include "rectangle.hpp"

namespace osfes {

    class Square : public Rectangle {
      public:
        Square(double x, double y, double width, Plane& p, Texture* t = nullptr) : Rectangle{x, y, width, width, p, t} {
        }

        Square(const Square& s) : Rectangle{s.getX(), s.getY(), s.getWidth(), s.getHeight(), s.getPlane(), s.getTexture()} {
        }

        ~Square() = default;

        virtual std::string getName() const {
            return "Square";
        }
    };
} // namespace osfes