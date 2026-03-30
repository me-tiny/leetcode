#include "lc.hpp"

class Solution {
  public:
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<std::string, std::vector<std::string>> freq;

        // sort and add to map
        for (size_t i = 0; i < strs.size(); i++) {
            std::string word = strs[i];
            std::sort(word.begin(), word.end());
            freq[word].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> res;
        for (auto m : freq) {
            res.push_back(m.second);
        }

        return res;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<std::string> s1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> e1 = {
        {"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
    expect_unordered(s.groupAnagrams(s1), e1);

    std::vector<std::string> s2 = {""};
    std::vector<std::vector<std::string>> e2 = {{""}};
    expect_unordered(s.groupAnagrams(s2), e2);

    std::vector<std::string> s3 = {"a"};
    std::vector<std::vector<std::string>> e3 = {{"a"}};
    expect_unordered(s.groupAnagrams(s3), e3);

    return 0;
}
