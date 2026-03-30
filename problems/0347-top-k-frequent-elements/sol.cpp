#include "lc.hpp"

class Solution {
  public:
    // time: O(n)
    // space: O(n)
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> freq; // num : frequency
        for (size_t i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (auto &[num, count] : freq) {
            buckets[count].push_back(num);
        }

        std::vector<int> top_k;
        for (int i = buckets.size() - 1;
             i >= 1 && top_k.size() < static_cast<size_t>(k); i--) {
            for (const auto &num : buckets[i]) {
                top_k.push_back(num);
                if (top_k.size() == static_cast<size_t>(k))
                    break;
            }
        }

        return top_k;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<int> n1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    std::vector<int> e1 = {1, 2};
    expect_unordered(s.topKFrequent(n1, k1), e1);

    std::vector<int> n2 = {1};
    int k2 = 1;
    std::vector<int> e2 = {1};
    expect_unordered(s.topKFrequent(n2, k2), e2);

    std::vector<int> n3 = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k3 = 2;
    std::vector<int> e3 = {1, 2};
    expect_unordered(s.topKFrequent(n3, k3), e3);

    return 0;
}
