#include "gmock/gmock.h"
#include "Baseball.cpp"
TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched)
{
    Baseball game;
    EXPECT_THROW(game.guess(string("12")), std::length_error);
}
int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}
