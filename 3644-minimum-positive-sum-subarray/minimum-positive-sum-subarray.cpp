class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_sum = -1;
        int n = nums.size();
        
        for (int size = l; size <= r; ++size) {
            int current_sum = 0;
            for (int i = 0; i < n; ++i) {
                current_sum += nums[i];
                if (i >= size) {
                    current_sum -= nums[i - size];
                }
                if (i >= size - 1) {
                    if (current_sum > 0) {
                        if (min_sum == -1 || current_sum < min_sum) {
                            min_sum = current_sum;
                        }
                    }
                }
            }
        }
        
        return min_sum;
    }
};