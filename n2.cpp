#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1, right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    
    std::vector<int> nums(n);
    std::cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    std::vector<std::vector<int>> results = solution.threeSum(nums);
    
    if (results.empty()) {
        std::cout << "No triplets found that sum to 0" << std::endl;
    } else {
        std::cout << "Triplets that sum to 0: " << std::endl;
        for (const auto& triplet : results) {
            for (int num : triplet) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}
