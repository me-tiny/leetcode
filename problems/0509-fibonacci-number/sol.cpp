#include "lc.hpp"

class Solution {
  public:
    // iterative bottom up
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int cur = 0;
        int prev1 = 1;
        int prev2 = 0;

        for (int i = 2; i < n + 1; i++) {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};

int main() {
    Solution s;

    // test cases
    int n1 = 2;
    int e1 = 1;
    expect(s.fib(n1), e1);

    int n2 = 3;
    int e2 = 2;
    expect(s.fib(n2), e2);

    int n3 = 4;
    int e3 = 3;
    expect(s.fib(n3), e3);

    return 0;
}
