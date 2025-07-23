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

        Rectangle(const Rectangle& r) : position{r.position}, width{r.width}, height{r.height}, texture{r.texture}, plane{r.plane} {
        }

        double getX() const {
            return position.x;
        }

        double getY() const {
            return position.y;
        }

        double getWidth() const {
            return width;
        }

        double getHeight() const {
            return height;
        }

        void setTexture(Texture* t) {
            texture = t;
        }

        Texture* getTexture() const {
            return texture;
        }

        Plane& getPlane() const {
            return plane;
        }
    };
} // namespace osfes