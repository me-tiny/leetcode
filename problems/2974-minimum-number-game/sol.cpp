#include "lc.hpp"

class Solution {
  public:
    std::vector<int> numberGame(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i += 2) {
            std::swap(nums.at(i), nums.at(i + 1));
        }
        return nums;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<int> n1 = {5, 4, 2, 3};
    std::vector<int> e1 = {3, 2, 5, 4};
    expect(s.numberGame(n1), e1);

    std::vector<int> n2 = {2, 5};
    std::vector<int> e2 = {5, 2};
    expect(s.numberGame(n2), e2);

    return 0;
}
