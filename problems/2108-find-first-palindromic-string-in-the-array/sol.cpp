#include "lc.hpp"

class Solution {
  public:
    std::string firstPalindrome(std::vector<std::string> &words) {
        std::string res = "";

        for (size_t i = 0; i < words.size(); i++) {
            bool found = true;
            size_t l = 0;
            size_t r = words.at(i).size() - 1;
            while (l < r) {
                // if they aren't equal, break
                if (words.at(i).at(l) != words.at(i).at(r)) {
                    found = false;
                    break;
                }
                l++;
                r--;
            }
            if (found) {
                res = words.at(i);
                return res;
            }
        }

        return res;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<std::string> w1 = {"abc", "car", "ada", "racecar", "cool"};
    std::string e1 = "ada";
    expect(s.firstPalindrome(w1), e1);

    std::vector<std::string> w2 = {"notapalindrome", "racecar"};
    std::string e2 = "racecar";
    expect(s.firstPalindrome(w2), e2);

    std::vector<std::string> w3 = {"def", "ghi"};
    std::string e3 = "";
    expect(s.firstPalindrome(w3), e3);

    return 0;
}
