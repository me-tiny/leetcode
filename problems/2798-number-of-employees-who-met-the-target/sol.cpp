#include "lc.hpp"

class Solution {
  public:
    int numberOfEmployeesWhoMetTarget(std::vector<int> &hours, int target) {
        int res = 0;
        for (auto n : hours) {
            if (n >= target) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;

    // test cases
    std::vector<int> h1 = {0, 1, 2, 3, 4};
    int t1 = 2;
    int e1 = 3;
    expect(s.numberOfEmployeesWhoMetTarget(h1, t1), e1);

    std::vector<int> h2 = {5, 1, 4, 2, 2};
    int t2 = 6;
    int e2 = 0;
    expect(s.numberOfEmployeesWhoMetTarget(h2, t2), e2);

    return 0;
}
