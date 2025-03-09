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
            if (i > 0 && nums[i] == nums[i-1]) continue;

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
                else if (sum < 0) left++;
                else right--;
            }
        }
        
        return result;
    }
};

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) std::cin >> nums[i];

    Solution solution;
    std::vector<std::vector<int>> result = solution.threeSum(nums);

    std::cout << "Output: [";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) std::cout << ",";
        }
        std::cout << "]";
        if (i < result.size() - 1) std::cout << ",";
    }
    std::cout << "]\n";

    return 0;
}
