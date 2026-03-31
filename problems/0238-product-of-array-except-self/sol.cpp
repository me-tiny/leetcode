#include "lc.hpp"

class Solution {
  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {
        std::vector<int> result(nums.size());
        std::fill(result.begin(), result.end(), 1);

        int prefix = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            result.at(i) = prefix;
            prefix *= nums.at(i);
        }
        int postfix = 1;
        for (int i = nums.size() - 1; -1 < i; i--) {
            result.at(i) *= postfix;
            postfix *= nums.at(i);
        }
        return result;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<int> n1 = {1, 2, 3, 4};
    std::vector<int> e1 = {24, 12, 8, 6};
    expect(s.productExceptSelf(n1), e1);

    std::vector<int> n2 = {-1, 1, 0, -3, 3};
    std::vector<int> e2 = {0, 0, 9, 0, 0};
    expect(s.productExceptSelf(n2), e2);

    return 0;
}
