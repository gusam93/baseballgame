#include "gmock/gmock.h"
#include "Baseball.cpp"

class BaseballFixture :public ::testing::Test {
public:
    void assertIllegalArgument(const string& guessNumber) {
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception& e) {
            // PASS
        }
    }
    Baseball game{ "123" };
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase)
{
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
    assertIllegalArgument("121");
}
TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber)
{
    GuessResult result = game.guess("123");
    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);

}
int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}
