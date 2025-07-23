#pragma once

namespace osfes {
    class MyCountableClass {
      private:
        static inline int count{0};
        int               myNumber{};

      public:
        static int getCount() {
            return count;
        }

        int getMyNumber() {
            return myNumber;
        }

        MyCountableClass() {
            myNumber = count;
            count++;
        }
    };
} // namespace osfes