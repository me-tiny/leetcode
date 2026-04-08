#include "lc.hpp"

class Solution {
  public:
    int sum(int n, int k) {
        int count = n / k;
        return k * count * (count + 1) / 2;
    }

    int sumOfMultiples(int n) {
        // int res = 0;
        // for (int i = 1; i <= n; i++) {
        //     if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
        //         res += i;
        //     }
        // }
        // return res;

        // inclusion-exclusion principle
        return sum(n, 3) + sum(n, 5) + sum(n, 7) - sum(n, 15) - sum(n, 35) -
               sum(n, 21) + sum(n, 105);
    }
};

int main() {
    Solution s;

    // test cases
    int n1 = 7;
    int e1 = 21;
    expect(s.sumOfMultiples(n1), e1);

    int n2 = 10;
    int e2 = 40;
    expect(s.sumOfMultiples(n2), e2);

    int n3 = 9;
    int e3 = 30;
    expect(s.sumOfMultiples(n3), e3);

    return 0;
}
