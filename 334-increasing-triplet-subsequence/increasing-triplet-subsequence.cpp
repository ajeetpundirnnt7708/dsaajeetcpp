class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        
        for (int num : nums) {
            if (num <= first) {
                first = num;            // Found a new smallest element
            } else if (num <= second) {
                second = num;           // Found an element greater than first, but <= second
            } else {
                return true;            // Found an element greater than both first and second
            }
        }
        
        return false;
    }
};