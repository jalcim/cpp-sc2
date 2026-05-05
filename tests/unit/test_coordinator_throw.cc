#include <doctest/doctest.h>

#include <exception>
#include <stdexcept>
#include <string>

#include "sc2api/sc2_errors.h"

TEST_CASE("ClientConnectionError(const std::string&) constructor exists") {
    sc2::ClientConnectionError err("test reason");
    const std::string msg = err.what();
    CHECK(msg.find("test reason") != std::string::npos);
}

TEST_CASE("ClientConnectionError(net_address, port) constructor still available") {
    sc2::ClientConnectionError err("127.0.0.1", 5000);
    const char* msg = err.what();
    CHECK(msg != nullptr);
}

TEST_CASE("ClientConnectionError is catchable via std::exception") {
    bool caught = false;
    try {
        throw sc2::ClientConnectionError("simulated");
    } catch (const std::exception& e) {
        caught = true;
        CHECK(std::string(e.what()).find("simulated") != std::string::npos);
    }
    CHECK(caught);
}
