#include "lc.hpp"

class Solution {
  public:
    std::string toLowerCase(std::string s) {
        for (size_t i = 0; i < s.size(); i++) {
            if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
                s.at(i) = s.at(i) | ' ';
            }
        }
        return s;
    }
};

int main() {
    Solution s;

    // test cases
    std::string s1 = "Hello";
    std::string e1 = "hello";
    expect(s.toLowerCase(s1), e1);

    std::string s2 = "here";
    std::string e2 = "here";
    expect(s.toLowerCase(s2), e2);

    std::string s3 = "LOVELY";
    std::string e3 = "lovely";
    expect(s.toLowerCase(s3), e3);

    std::string s4 = "Hello@[]";
    std::string e4 = "hello@[]";
    expect(s.toLowerCase(s4), e4);

    return 0;
}
