#include <doctest/doctest.h>

#include "sc2api/sc2_unit.h"

TEST_CASE("Unit defaults: is_active=false, buff_durations=0, rally_targets empty") {
    sc2::Unit u;
    CHECK(u.is_active == false);
    CHECK(u.buff_duration_remain == 0);
    CHECK(u.buff_duration_max == 0);
    CHECK(u.rally_targets.empty());
}

TEST_CASE("RallyTarget struct can be initialized") {
    sc2::RallyTarget rt;
    rt.point = sc2::Point3D{10.0f, 20.0f, 0.0f};
    rt.tag = 4242ULL;
    CHECK(rt.point.x == doctest::Approx(10.0f));
    CHECK(rt.point.y == doctest::Approx(20.0f));
    CHECK(rt.tag == 4242ULL);
}

TEST_CASE("UnitOrder.target_pos preserves z coordinate") {
    sc2::UnitOrder order;
    order.ability_id = sc2::ABILITY_ID::ATTACK;
    order.target_pos = sc2::Point3D{1.0f, 2.0f, 3.0f};

    CHECK(order.target_pos.x == doctest::Approx(1.0f));
    CHECK(order.target_pos.y == doctest::Approx(2.0f));
    CHECK(order.target_pos.z == doctest::Approx(3.0f));
}

TEST_CASE("UnitOrder default target_pos is (0, 0, 0)") {
    sc2::UnitOrder order;
    CHECK(order.target_pos.x == doctest::Approx(0.0f));
    CHECK(order.target_pos.y == doctest::Approx(0.0f));
    CHECK(order.target_pos.z == doctest::Approx(0.0f));
}
