#pragma once

namespace osfes {
    class Plane {
      private:
        double width{};
        double height{};

      public:
        Plane(double w, double h) : width{w}, height{h} {
        }

        double getWidth() {
            return width;
        }

        double getHeight() {
            return height;
        }
    };
} // namespace osfes