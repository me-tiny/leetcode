#include "lc.hpp"
#include <string>

class Solution {
  public:
    // O(n)
    std::string encode(std::vector<std::string> &strs) {
        std::string result = "";

        for (const auto &s : strs) {
            result.append(std::to_string(s.size()) + ";" + s);
        }

        return result;
    }

    // O(n)
    std::vector<std::string> decode(std::string s) {
        // char static const DELIM = ';';
        std::vector<std::string> result;
        size_t pos = 0;

        while (pos < s.length()) {
            size_t found = s.find(';', pos);

            int num_len = std::stoi(s.substr(pos, found - pos));
            result.push_back(s.substr(found + 1, num_len));
            pos = found + 1 + num_len;
        }

        return result;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<std::string> s1 = {"hello", "world"};
    expect(s.decode(s.encode(s1)), s1);

    std::vector<std::string> s2 = {"", ""};
    expect(s.decode(s.encode(s2)), s2);

    std::vector<std::string> s3 = {};
    expect(s.decode(s.encode(s3)), s3);

    std::vector<std::string> s4 = {"123", "456"};
    expect(s.decode(s.encode(s4)), s4);

    std::vector<std::string> s5 = {"he#llo", "wo#rld"};
    expect(s.decode(s.encode(s5)), s5);

    std::vector<std::string> s6 = {""};
    expect(s.decode(s.encode(s6)), s6);

    std::vector<std::string> s7 = {"", "a", "", "b", ""};
    expect(s.decode(s.encode(s7)), s7);

    std::vector<std::string> s8 = {"abcdefghijklmnop"};
    expect(s.decode(s.encode(s8)), s8);

    return 0;
}
