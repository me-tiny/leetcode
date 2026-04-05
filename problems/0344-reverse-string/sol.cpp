#include "lc.hpp"

class Solution {
  public:
    void reverseString(std::vector<char> &s) {
        size_t l = 0;
        size_t r = s.size() - 1;
        while (l < r) {
            std::swap(s.at(l), s.at(r));
            l++;
            r--;
        }
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> e1 = {'o', 'l', 'l', 'e', 'h'};
    s.reverseString(s1);
    expect(s1, e1);

    std::vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    std::vector<char> e2 = {'h', 'a', 'n', 'n', 'a', 'H'};
    s.reverseString(s2);
    expect(s2, e2);

    return 0;
}
