#include <gtest/gtest.h>

struct TestFixture : public ::testing::Test
{
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F( TestFixture, TEST )
{
}