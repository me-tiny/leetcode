#include "lc.hpp"

class Solution {
  public:
    int differenceOfSum(std::vector<int> &nums) {
        int ele_sum = 0;
        int digit_sum = 0;

        for (auto n : nums) {
            ele_sum += n;
            digit_sum += (n / 1000) + (n / 100 % 10) + (n / 10 % 10) + (n % 10);
        }

        return std::abs(ele_sum - digit_sum);
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<int> n1 = {1, 15, 6, 3};
    int e1 = 9;
    expect(s.differenceOfSum(n1), e1);

    std::vector<int> n2 = {1, 2, 3, 4};
    int e2 = 0;
    expect(s.differenceOfSum(n2), e2);

    std::vector<int> n3 = {10, 15, 22, 123};
    // 170 - 17 = 153
    int e3 = 153;
    expect(s.differenceOfSum(n3), e3);

    return 0;
}
