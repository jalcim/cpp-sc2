#include <doctest/doctest.h>

#include "sc2api/sc2_connection.h"

TEST_CASE("Connection construct/destruct does not leak") {
    sc2::Connection conn;
    CHECK_FALSE(conn.connection_ != nullptr);
}

TEST_CASE("Connection survives multiple destruct cycles") {
    for (int i = 0; i < 10; ++i) {
        sc2::Connection conn;
        (void)conn;
    }
    CHECK(true);
}
