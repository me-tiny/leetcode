#include "lc.hpp"

class Solution {
  public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length())
            return false;

        std::unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        for (char c : t) {
            freq[c]--;
        }

        for (auto c : freq) {
            if (c.second != 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    // test cases
    std::string s1 = "anagram";
    std::string t1 = "nagaram";
    expect(s.isAnagram(s1, t1), true);

    std::string s2 = "rat";
    std::string t2 = "car";
    expect(s.isAnagram(s2, t2), true);

    return 0;
}
