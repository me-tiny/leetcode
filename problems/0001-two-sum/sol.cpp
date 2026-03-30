#include "lc.hpp"

class Solution {
  public:
    // O(n) runtime, O(n) memory; bit expensive on memory
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::vector<int> fin;
        std::unordered_map<int, int> seen; // num : ix
        for (size_t i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (seen.contains(diff)) {
                fin.push_back(static_cast<int>(i));
                fin.push_back(seen[diff]);
            } else {
                seen[nums[i]] = static_cast<int>(i);
            }
        }
        return fin;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<int> n1 = {2, 7, 11, 15};
    int t1 = 9;
    std::vector<int> e1 = {0, 1};
    expect_unordered(s.twoSum(n1, t1), e1);

    std::vector<int> n2 = {3, 2, 4};
    int t2 = 6;
    std::vector<int> e2 = {1, 2};
    expect_unordered(s.twoSum(n2, t2), e2);

    std::vector<int> n3 = {3, 3};
    int t3 = 6;
    std::vector<int> e3 = {0, 1};
    expect_unordered(s.twoSum(n3, t3), e3);

    return 0;
}
