#pragma once

#include "plane.hpp"
#include "point.hpp"
#include "rectangle.hpp"
#include "texture.hpp"

namespace osfes {

    class Square : public Rectangle {
      public:
        Square(double x, double y, double width, Plane& p, Texture* t = nullptr) : Rectangle{x, y, width, width, p, t} {
        }

        Square(const Square& s) : Rectangle{s.getX(), s.getY(), s.getWidth(), s.getHeight(), s.getPlane(), s.getTexture()} {
        }
    };
} // namespace osfes