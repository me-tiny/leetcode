#include "lc.hpp"

class Solution {
  public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        return n * (n + 1) / 2 - k * (k + 1) * m;
    }
};

int main() {
    Solution s;

    // test cases
    int n1 = 10;
    int m1 = 3;
    int e1 = 19;
    expect(s.differenceOfSums(n1, m1), e1);

    int n2 = 5;
    int m2 = 6;
    int e2 = 15;
    expect(s.differenceOfSums(n2, m2), e2);

    int n3 = 5;
    int m3 = 1;
    int e3 = -15;
    expect(s.differenceOfSums(n3, m3), e3);

    return 0;
}
