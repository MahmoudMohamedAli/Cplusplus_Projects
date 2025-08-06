#include "gtest/gtest.h"
#include "Vector.h"
#include <vector>

TEST(TEST_SUIT1, TESTCASE1)
{
    std::vector<int> stdVec = {1, 2, 3, 4, 5};
    Vector<int> customVec(5);
    for (int i = 0; i < 5; ++i) {
        customVec[i] = stdVec[i];
    }
    EXPECT_EQ(customVec.size(), stdVec.size());
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(customVec[i], stdVec[i]);
    }
}

//continue with more test cases to test all functionalities of the Vector class