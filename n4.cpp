#include <iostream>
#include <vector>

long long countWays(std::vector<int>& nums, int target) {
    std::vector<long long> dp(target + 1);
    dp[0] = 1;
    
    for (int i = 0; i <= target; i++) {
        if (dp[i] > 0) {
            for (int num : nums) {
                if (i + num <= target) {
                    dp[i + num] += dp[i];
                }
            }
        }
    }
    
    return dp[target];
}

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
    
    long long result = countWays(nums, target);
    std::cout << "Number of ways: " << result << std::endl;
    
    return 0;
}
