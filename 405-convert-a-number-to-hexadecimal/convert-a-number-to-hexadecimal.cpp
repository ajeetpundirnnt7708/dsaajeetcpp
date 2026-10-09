class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        string hexChars = "0123456789abcdef";
        string result = "";
        unsigned int uNum = num;
        
        while (uNum > 0) {
            result = hexChars[uNum & 0xF] + result;
            uNum >>= 4;
        }
        
        return result;
    }
};