#pragma once

#include "plane.hpp"
#include "point.hpp"
#include "texture.hpp"

namespace osfes {
    class Rectangle {
      private:
        Point    position;
        double   width{};
        double   height{};
        Texture* texture{};
        Plane&   plane;

      public:
        Rectangle(double x, double y, double w, double h, Plane& p, Texture* t = nullptr) : position{x, y}, width{w}, height{h}, plane{p}, texture{t} {
        }

        double getX() {
            return position.x;
        }

        double getY() {
            return position.y;
        }

        double getWidth() {
            return width;
        }

        double getHeight() {
            return height;
        }

        void setTexture(Texture* t) {
            texture = t;
        }

        Texture* getTexture() {
            return texture;
        }

        Plane& getPlane() {
            return plane;
        }
    };
} // namespace osfes