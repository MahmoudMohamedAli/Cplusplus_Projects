#include "gtest/gtest.h"
#include "Unique_Ptr.hpp" //include Unique_ptr.hpp"

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

    // // Test derived class functionality
    // Implementation_Unique_ptr::unique_ptr<Implementation_Unique_ptr::Base> base1(new Implementation_Unique_ptr::Derived1);
    // EXPECT_NO_THROW(base1->action());

    // Implementation_Unique_ptr::unique_ptr<Implementation_Unique_ptr::Base> base2(new Implementation_Unique_ptr::Derived2);
    // EXPECT_NO_THROW(base2->action());
}