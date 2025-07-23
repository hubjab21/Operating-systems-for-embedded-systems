#pragma once

namespace osfes {
    class Point {
      public:
        double x{};
        double y{};

        Point(double xpos, double ypos) : x{xpos}, y{ypos} {
        }
    };
} // namespace osfes