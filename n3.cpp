#include <iostream>
#include <vector>
#include <algorithm>

int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
    int n = startTime.size();
    std::vector<std::vector<int>> jobs(n);
    
    for (int i = 0; i < n; i++) {
        jobs[i] = {endTime[i], startTime[i], profit[i]};
    }
    
    std::sort(jobs.begin(), jobs.end());
    
    std::vector<int> dp(n);
    dp[0] = jobs[0][2];
    
    for (int i = 1; i < n; i++) {
        int currProfit = jobs[i][2];
        int prevNonConflict = -1;
        
        for (int j = i - 1; j >= 0; j--) {
            if (jobs[j][0] <= jobs[i][1]) {
                prevNonConflict = j;
                break;
            }
        }
        
        if (prevNonConflict != -1) {
            currProfit += dp[prevNonConflict];
        }
        
        dp[i] = std::max(dp[i-1], currProfit);
    }
    
    return dp[n-1];
}

int main() {
    int n;
    std::cout << "Enter number of jobs: ";
    std::cin >> n;
    
    std::vector<int> startTime(n);
    std::vector<int> endTime(n);
    std::vector<int> profit(n);
    
    std::cout << "Enter " << n << " start times: ";
    for (int i = 0; i < n; i++) {
        std::cin >> startTime[i];
    }
    
    std::cout << "Enter " << n << " end times: ";
    for (int i = 0; i < n; i++) {
        std::cin >> endTime[i];
    }
    
    std::cout << "Enter " << n << " profits: ";
    for (int i = 0; i < n; i++) {
        std::cin >> profit[i];
    }
    
    int result = jobScheduling(startTime, endTime, profit);
    std::cout << "Maximum profit: " << result << std::endl;
    
    return 0;
}
