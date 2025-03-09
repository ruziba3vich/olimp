#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 1;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
            
            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        }
        
        return s.substr(start, maxLength);
    }
};

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::cin >> s;

    Solution solution;
    std::string result = solution.longestPalindrome(s);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
