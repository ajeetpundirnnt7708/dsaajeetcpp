#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> ans(k, 0);
        // dp[r] stores the count of subarrays ending at the current position with product % k == r
        std::vector<long long> dp(k, 0);

        for (int num : nums) {
            std::vector<long long> next_dp(k, 0);
            int rem = num % k;

            // Start a new subarray consisting solely of the current element
            next_dp[rem]++;

            // Extend existing subarrays with the current element
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * rem) % k;
                    next_dp[new_rem] += dp[r];
                }
            }

            // Accumulate counts into the final result
            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return ans;
    }
};