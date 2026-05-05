#include <doctest/doctest.h>

#include <array>

#include "sc2api/sc2_client.h"

namespace {

struct MockClientEvents : public sc2::ClientEvents {
    std::array<bool, 22> fired{};

    void OnAlertError() override {
        fired[0] = true;
    }
    void OnAlertAddOnComplete() override {
        fired[1] = true;
    }
    void OnAlertBuildingComplete() override {
        fired[2] = true;
    }
    void OnAlertBuildingUnderAttack() override {
        fired[3] = true;
    }
    void OnAlertLarvaHatched() override {
        fired[4] = true;
    }
    void OnAlertMergeComplete() override {
        fired[5] = true;
    }
    void OnAlertMineralsExhausted() override {
        fired[6] = true;
    }
    void OnAlertMorphComplete() override {
        fired[7] = true;
    }
    void OnAlertMothershipComplete() override {
        fired[8] = true;
    }
    void OnAlertMULEExpired() override {
        fired[9] = true;
    }
    void OnAlertNukeComplete() override {
        fired[10] = true;
    }
    void OnAlertResearchComplete() override {
        fired[11] = true;
    }
    void OnAlertTrainError() override {
        fired[12] = true;
    }
    void OnAlertTrainUnitComplete() override {
        fired[13] = true;
    }
    void OnAlertTrainWorkerComplete() override {
        fired[14] = true;
    }
    void OnAlertTransformationComplete() override {
        fired[15] = true;
    }
    void OnAlertUnitUnderAttack() override {
        fired[16] = true;
    }
    void OnAlertUpgradeComplete() override {
        fired[17] = true;
    }
    void OnAlertVespeneExhausted() override {
        fired[18] = true;
    }
    void OnAlertWarpInComplete() override {
        fired[19] = true;
    }
    void OnNydusDetected() override {
        fired[20] = true;
    }
    void OnNuclearLaunchDetected() override {
        fired[21] = true;
    }
};

}  // namespace

TEST_CASE("All 22 OnAlert* hooks are virtual and overridable") {
    MockClientEvents mock;
    mock.OnAlertError();
    mock.OnAlertAddOnComplete();
    mock.OnAlertBuildingComplete();
    mock.OnAlertBuildingUnderAttack();
    mock.OnAlertLarvaHatched();
    mock.OnAlertMergeComplete();
    mock.OnAlertMineralsExhausted();
    mock.OnAlertMorphComplete();
    mock.OnAlertMothershipComplete();
    mock.OnAlertMULEExpired();
    mock.OnAlertNukeComplete();
    mock.OnAlertResearchComplete();
    mock.OnAlertTrainError();
    mock.OnAlertTrainUnitComplete();
    mock.OnAlertTrainWorkerComplete();
    mock.OnAlertTransformationComplete();
    mock.OnAlertUnitUnderAttack();
    mock.OnAlertUpgradeComplete();
    mock.OnAlertVespeneExhausted();
    mock.OnAlertWarpInComplete();
    mock.OnNydusDetected();
    mock.OnNuclearLaunchDetected();

    for (size_t i = 0; i < mock.fired.size(); ++i) {
        CAPTURE(i);
        CHECK(mock.fired[i]);
    }
}
