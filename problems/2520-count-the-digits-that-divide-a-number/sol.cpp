#include "lc.hpp"

class Solution {
  public:
    int countDigits(int num) {
        int res = 0;
        int cur = num;

        while (cur != 0) {
            int lsd = cur % 10;
            if (num % lsd == 0) {
                res++;
            }
            cur = cur / 10;
        }
        return res;
    }
};

int main() {
    Solution s;

    // test cases
    int n1 = 7;
    int e1 = 1;
    expect(s.countDigits(n1), e1);

    int n2 = 121;
    int e2 = 2;
    expect(s.countDigits(n2), e2);

    int n3 = 1248;
    int e3 = 4;
    expect(s.countDigits(n3), e3);

    return 0;
}
