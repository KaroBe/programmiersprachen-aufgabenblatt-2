#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "vec2.hpp"

TEST_CASE("describe_custom_constructor", "[constructor vec2]")
{
	Vec2 v1{1.5f,1.5f};
	REQUIRE(1.5f == v1.x);
	REQUIRE(1.5f == v1.y);
}

TEST_CASE("describe_default_constructor", "[constructor vec2]")
{
	Vec2 v2;
	REQUIRE(0.0f == v2.x);
	REQUIRE(0.0f == v2.y);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
