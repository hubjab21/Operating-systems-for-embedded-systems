#pragma once

#include "plane.hpp"
#include "point.hpp"
#include "texture.hpp"

namespace osfes {
    class Shape {
      private:
        Point    position;
        Plane&   plane;
        Texture* texture;

      public:
        Shape(double x, double y, Plane& p, Texture* t = nullptr) : position{x, y}, plane{p}, texture{t} {
        }

        Shape(Shape& s) : position{s.position}, plane{s.plane}, texture{s.texture} {
        }

        ~Shape() = default;

        double getX() const {
            return position.x;
        }

        double getY() const {
            return position.y;
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

        virtual double getArea() const = 0;

        virtual std::string getName() const = 0;
    };
} // namespace osfes