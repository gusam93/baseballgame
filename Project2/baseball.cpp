#include <stdexcept>
#include <string>


using std::string;
using std::exception;
class Baseball {
public:
    void guess(const string& guessNumber) {
        assertIllegalArgument(guessNumber);
    }
private:
    void assertIllegalArgument(const std::string& guessNumber)
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
    bool isDuplicateNumber(const std::string& guessNumber)
    {
        return guessNumber[0] == guessNumber[1]
            || guessNumber[0] == guessNumber[2]
            || guessNumber[1] == guessNumber[2];
    }

};