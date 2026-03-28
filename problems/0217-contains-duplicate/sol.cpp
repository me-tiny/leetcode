#include "lc.hpp"

class Solution {
  public:
    bool containsDuplicate(std::vector<int> nums) {
        std::unordered_map<int, int> seen;

        for (size_t i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }
            seen[nums[i]] = 1;
        }
        return false;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<int> t1{1, 2, 3, 1};
    expect(s.containsDuplicate(t1), true);

    std::vector<int> t2{1, 2, 3, 4};
    expect(s.containsDuplicate(t2), false);

    std::vector<int> t3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    expect(s.containsDuplicate(t3), true);

    return 0;
}
