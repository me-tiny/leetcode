#include "lc.hpp"

class Solution {
  public:
    int mostWordsFound(std::vector<std::string> &sentences) {
        int max = 0;
        for (size_t i = 0; i < sentences.size(); i++) {
            int len =
                std::count(sentences.at(i).begin(), sentences.at(i).end(), ' ');
            max = std::max(max, len + 1);
        }
        return max;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<std::string> s1 = {"alice and bob love leetcode",
                                   "i think so too",
                                   "this is great thanks very much"};
    int e1 = 6;
    expect(s.mostWordsFound(s1), e1);

    std::vector<std::string> s2 = {"please wait", "continue to fight",
                                   "continue to win"};
    int e2 = 3;
    expect(s.mostWordsFound(s2), e2);

    return 0;
}
