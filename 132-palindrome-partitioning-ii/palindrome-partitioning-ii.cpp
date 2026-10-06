#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCut(std::string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // isPal[i][j] will be true if substring s[i..j] is a palindrome
        std::vector<std::vector<bool>> isPal(n, std::vector<bool>(n, false));

        // Fill the palindrome table
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2 || isPal[i + 1][j - 1]) {
                        isPal[i][j] = true;
                    }
                }
            }
        }

        // dp[i] stores min cuts for prefix s[0..i]
        std::vector<int> dp(n);

        for (int i = 0; i < n; ++i) {
            if (isPal[0][i]) {
                dp[i] = 0;
            } else {
                int minCuts = i; // Max possible cuts for s[0..i] is i
                for (int j = 1; j <= i; ++j) {
                    if (isPal[j][i]) {
                        minCuts = std::min(minCuts, dp[j - 1] + 1);
                    }
                }
                dp[i] = minCuts;
            }
        }

        return dp[n - 1];
    }
};