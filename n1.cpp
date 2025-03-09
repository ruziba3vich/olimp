#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 1, n = s.length();

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    Solution solution;
    std::string s;
    std::getline(std::cin, s);
    std::cout << solution.longestPalindrome(s) << std::endl;
    return 0;
}
