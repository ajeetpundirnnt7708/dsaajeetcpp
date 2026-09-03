class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = *min_element(nums1.begin(), nums1.end());

        if (min_val % 2 != 0) {
            return true;
        }

        for (int x : nums1) {
            if (x % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};