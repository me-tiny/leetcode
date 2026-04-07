#include "lc.hpp"

class Solution {
  public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        } else if (num % 9 == 0) {
            return 9;
        }
        return num % 9;
    }
};

int main() {
    Solution s;

    // test cases
    int n1 = 38;
    int e1 = 2;
    expect(s.addDigits(n1), e1);

    int n2 = 0;
    int e2 = 0;
    expect(s.addDigits(n2), e2);

    return 0;
}
