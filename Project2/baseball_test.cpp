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
    Baseball game;
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase)
{
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}
