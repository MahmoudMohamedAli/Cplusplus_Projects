#include "gtest/gtest.h"
#include "Unique_Ptr.hpp" 

TEST(TEST_SUIT1, TESTCASE1)
{
    Implementation_Unique_ptr::unique_ptr<int> up1(new int{ 8 });
    EXPECT_EQ(*up1, 8);

    Implementation_Unique_ptr::unique_ptr<int> up2(new int{ 6 });
    Implementation_Unique_ptr::unique_ptr<int> up3 = nullptr; // calls nullptr ctor

    up3 = std::move(up2);
    EXPECT_EQ(*up3, 6);

    Implementation_Unique_ptr::unique_ptr<int> up4(std::move(up3));
    EXPECT_EQ(*up4, 6);
}

// add more test cases for derived classes in future ISA :)