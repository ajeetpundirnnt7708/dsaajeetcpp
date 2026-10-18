class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;
        for (char c : columnTitle) {
            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};