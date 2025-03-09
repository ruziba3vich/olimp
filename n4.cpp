#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        std::vector<int> dp(2 * totalSum + 1, 0);

        dp[nums[0] + totalSum] = 1;
        dp[-nums[0] + totalSum] += 1;

        for (int index = 1; index < nums.size(); index++) {
            std::vector<int> next(2 * totalSum + 1, 0);
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[sum + totalSum] > 0) {
                    next[sum + nums[index] + totalSum] += dp[sum + totalSum];
                    next[sum - nums[index] + totalSum] += dp[sum + totalSum];
                }
            }
            dp = next;
        }

        return std::abs(target) > totalSum ? 0 : dp[target + totalSum];
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
    int result = solution.findTargetSumWays(nums, target);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
