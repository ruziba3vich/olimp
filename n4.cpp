#include <iostream>
#include <vector>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};

int main() {
    int n, target;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::cout << "Enter target sum: ";
    std::cin >> target;

    Solution solution;
    int result = solution.combinationSum4(nums, target);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
