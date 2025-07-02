#include <stdexcept>
#include <string>

using std::string;
using std::exception;

struct GuessResult {
    bool solved;
    int strikes;
    int balls;
};
class Baseball {
public:
    Baseball(const string& question) :question(question) {}
    GuessResult guess(const string& guessNumber) {
        assertIllegalArgument(guessNumber);
        if (guessNumber == question) {
            return { true, 3, 0 };
        }
        return { false, 3, 0 };
    }
    void assertIllegalArgument(const string& guessNumber)
    {
        if (guessNumber.length() != 3) {
            throw std::length_error("Must be three letters");
        }
        for (auto ch : guessNumber) {
            if (ch >= '0' && ch <= '9') continue;
            throw std::invalid_argument("Must be number");
        }
        if (isDuplicateNumber(guessNumber)) {
            throw std::invalid_argument("Must not have same number");
        }
    }
    bool isDuplicateNumber(const string& guessNumber)
    {
        return guessNumber[0] == guessNumber[1]
            || guessNumber[0] == guessNumber[2]
            || guessNumber[1] == guessNumber[2];
    }
private:
    string question;
};