#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop as long as there are bits left to process or a carry remains
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i] - '0'; // Convert character bit to integer
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert character bit to integer
                j--;
            }
            
            // Append the remainder bit (0 or 1) to the result string
            result += std::to_string(sum % 2);
            
            // Calculate the new carry (either 0 or 1)
            carry = sum / 2;
        }
        
        // The result is built in reverse order, so reverse it before returning
        std::reverse(result.begin(), result.end());
        return result;
    }
};
