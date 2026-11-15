class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0;
        long long evenCount = 1; // prefix sum 0 is even
        long long currentSum = 0;
        long long totalOddSubarrays = 0;
        long long MOD = 1e9 + 7;

        for (int num : arr) {
            currentSum += num;
            if (currentSum % 2 != 0) {
                totalOddSubarrays = (totalOddSubarrays + evenCount) % MOD;
                oddCount++;
            } else {
                totalOddSubarrays = (totalOddSubarrays + oddCount) % MOD;
                evenCount++;
            }
        }

        return totalOddSubarrays;
    }
};