// Test File

#include <catch2/catch_test_macros.hpp>

#include "dummy.hpp"

TEST_CASE("Dummy Test", "[dummy]") {
  REQUIRE(add(2, 3) == 5);
  REQUIRE(returnFourtyTwo() == 42);
  REQUIRE(returnTrue() == true);
}

TEST_CASE("Negative Test", "[dummy][negative]") {
  REQUIRE(add(2, 3) != -5);
  REQUIRE(returnFourtyTwo() != 43);
  REQUIRE(returnTrue() != false);
}
