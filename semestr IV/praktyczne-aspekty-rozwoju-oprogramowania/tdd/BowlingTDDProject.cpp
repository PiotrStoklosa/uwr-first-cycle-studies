#include "catch/catch.hpp"
#include "BowlingGame.h"

class SimpleCalculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};

TEST_CASE("SimpleCalculator_add_test") {
    SimpleCalculator testObj;

    REQUIRE( testObj.add(2, 2) == 4);
    REQUIRE( testObj.add(2, 4) == 6);
}