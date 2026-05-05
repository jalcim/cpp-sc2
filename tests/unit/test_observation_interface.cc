#include <doctest/doctest.h>

#include "sc2api/sc2_data.h"
#include "sc2api/sc2_unit.h"

TEST_CASE("Effect default values for new fields") {
    sc2::Effect e;
    CHECK(e.alliance == 3);
    CHECK(e.owner == 0);
    CHECK(e.radius == doctest::Approx(0.0f));
}

TEST_CASE("Effect.alliance roundtrips to Unit::Alliance enum") {
    sc2::Effect e;
    e.alliance = static_cast<int32_t>(sc2::Unit::Alliance::Self);
    CHECK(static_cast<sc2::Unit::Alliance>(e.alliance) == sc2::Unit::Alliance::Self);
}

TEST_CASE("RadarRing struct has position and radius") {
    sc2::RadarRing r;
    r.position = sc2::Point2D{5.0f, 10.0f};
    r.radius = 25.0f;
    CHECK(r.position.x == doctest::Approx(5.0f));
    CHECK(r.position.y == doctest::Approx(10.0f));
    CHECK(r.radius == doctest::Approx(25.0f));
}

TEST_CASE("ActionError struct has unit_tag, ability_id, result") {
    sc2::ActionError ae;
    ae.unit_tag = 12345ULL;
    ae.ability_id = 56;
    ae.result = 4;
    CHECK(ae.unit_tag == 12345ULL);
    CHECK(ae.ability_id == 56);
    CHECK(ae.result == 4);
}
