#include <gtest/gtest.h>

#include "test_ST_mortality.h"

TEST(ST_Mortality_test, Simulate_prescribed_fire_when_killfreq_startyr_is_0) {
    GrpIndex rg = 0;
    RealF random_number = 0.0f;

    RGroup = (GroupType **)Mem_Calloc(1, sizeof(GroupType *), nullptr);
    RGroup[rg] = (GroupType *)Mem_Calloc(1, sizeof(GroupType), nullptr);
    RGroup[rg]->killfreq_startyr = 0;

    simulatePrescribedFire(rg, random_number);

    // If killfreq_startyr == 0, do not simulate fire.
    EXPECT_EQ(RGroup[rg]->prescribedfire, 0);

    Mem_Free((void *)RGroup[rg]);
    Mem_Free((void *)RGroup);
}