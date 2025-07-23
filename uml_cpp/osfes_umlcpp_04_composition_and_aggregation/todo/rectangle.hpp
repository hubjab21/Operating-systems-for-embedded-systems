#pragma once

#include "point.hpp"
#include "texture.hpp"

namespace osfes {
    class Rectangle {
      private:
        Point    position;
        double   width{};
        double   height{};
        Texture* texture{};

      public:
        Rectangle(double x, double y, double w, double h, Texture* t = nullptr) : position{x, y}, width{w}, height{h}, texture{t} {
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
    };
} // namespace osfes