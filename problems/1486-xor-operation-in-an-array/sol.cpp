#include "lc.hpp"

class Solution {
  public:
    // can be done in O(1)
    int xorOperation(int n, int start) {
        int end = start + 2 * n;
        int res = 0;
        for (int i = start; i < end; i += 2) {
            res = res ^ i;
        }
        return res;
    }
};

int main() {
    Solution s;

    // test cases
    int n1 = 5;
    int s1 = 0;
    int e1 = 8;
    expect(s.xorOperation(n1, s1), e1);

    int n2 = 4;
    int s2 = 3;
    int e2 = 8;
    expect(s.xorOperation(n2, s2), e2);

    return 0;
}
