#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        int maxCount = 0;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            // Update frequency of the current character
            count[s[right] - 'A']++;
            
            // Track the frequency of the most frequent character in the current window
            maxCount = std::max(maxCount, count[s[right] - 'A']);

            // Current window size is (right - left + 1).
            // If window size - maxCount > k, we need to shrink the window from the left.
            if ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};