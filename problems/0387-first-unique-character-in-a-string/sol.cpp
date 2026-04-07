#include "lc.hpp"

class Solution {
  public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> freq;
        for (size_t i = 0; i < s.size(); i++) {
            freq[s.at(i)]++;
        }
        for (size_t i = 0; i < s.size(); i++) {
            if (freq[s.at(i)] == 1) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
};

int main() {
    Solution s;

    // test cases
    std::string s1 = "leetcode";
    int e1 = 0;
    expect(s.firstUniqChar(s1), e1);

    std::string s2 = "loveleetcode";
    int e2 = 2;
    expect(s.firstUniqChar(s2), e2);

    std::string s3 = "aabb";
    int e3 = -1;
    expect(s.firstUniqChar(s3), e3);

    return 0;
}
