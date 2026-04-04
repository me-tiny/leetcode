#include "lc.hpp"

class Solution {
  public:
    std::vector<int> sortedSquares(std::vector<int> &nums) {
        std::vector<int> res(nums.size());
        int l = 0;
        int r = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int square;
            if (std::abs(nums[l]) < std::abs(nums[r])) {
                square = nums[r];
                r--;
            } else {
                square = nums[l];
                l++;
            }
            res[i] = square * square;
        }
        return res;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<int> n1 = {-4, -1, 0, 3, 10};
    std::vector<int> e1 = {0, 1, 9, 16, 100};
    expect(s.sortedSquares(n1), e1);

    std::vector<int> n2 = {-7, -3, 2, 3, 11};
    std::vector<int> e2 = {4, 9, 9, 49, 121};
    expect(s.sortedSquares(n2), e2);

    return 0;
}
