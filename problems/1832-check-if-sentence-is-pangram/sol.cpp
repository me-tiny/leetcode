#include "lc.hpp"

class Solution {
  public:
    bool checkIfPangram(std::string sentence) {
        std::unordered_set<char> seen(sentence.begin(), sentence.end());
        return (seen.size() == 26);
    }
};

int main() {
    Solution s;

    // test cases
    std::string s1 = "thequickbrownfoxjumpsoverthelazydog";
    expect(s.checkIfPangram(s1), true);

    std::string s2 = "leetcode";
    expect(s.checkIfPangram(s2), false);

    return 0;
}
