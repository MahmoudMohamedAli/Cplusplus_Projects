#include "shard_ptr_class.hpp"
#include <gtest/gtest.h>

TEST(ShardPtrTest, UseCount) {
    shard_ptr_class<int> ptr(new int(5));
    shard_ptr_class<int> ptr2(ptr);
    EXPECT_EQ(ptr.use_count(), 2); // Should print 2
    ptr.reset();
    EXPECT_EQ(ptr2.use_count(), 1); // Should print 1
    ptr2.reset();
    EXPECT_EQ(ptr2.use_count(), 0); // Should print 0
}
///cnt .................