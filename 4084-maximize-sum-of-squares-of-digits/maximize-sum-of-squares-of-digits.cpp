#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
       
        if ((long long)num * 9 < sum || sum < 1) {
            return "";
        }

        std::string result = "";
        for (int i = 0; i < num; ++i) {
            
            int max_possible = std::min(9, sum);
            
            
            int d = max_possible;
            while (d >= 0) {
                if (sum - d <= (num - 1 - i) * 9) {
                    break;
                }
                d--;
            }
            
            result += std::to_string(d);
            sum -= d;
        }

        if (sum > 0) {
            return "";
        }

        return result;
    }
};