#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> threeSum(std::vector<int>& nums) {
    std::vector<int> result;
    int n = nums.size();
    if (n < 3) return result;
    
    std::sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result = {nums[i], nums[left], nums[right]};
                return result;
            }
            else if (sum < 0) left++;
            else right--;
        }
    }
    
    return result;
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    
    std::vector<int> nums(n);
    std::cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    std::vector<int> result = threeSum(nums);
    
    if (result.empty()) {
        std::cout << "No triplet found that sums to 0" << std::endl;
    } else {
        std::cout << "Triplet that sums to 0: ";
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
