#include <vector>
#include <algorithm>

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long K = r - l + 1;
        long long MOD = 1000000007;
        
        if (n == 1) return K % MOD;
        if (n == 2) return (K * (K - 1)) % MOD;
        
        std::vector<long long> dp0(K + 2, 0);
        std::vector<long long> dp1(K + 2, 0);
        std::vector<long long> next_dp0(K + 2, 0);
        std::vector<long long> next_dp1(K + 2, 0);
        std::vector<long long> pref0(K + 2, 0);
        std::vector<long long> pref1(K + 2, 0);
        
        for (int v = 1; v <= K; ++v) {
            dp0[v] = K - v;
            dp1[v] = v - 1;
        }
        
        for (int i = 3; i <= n; ++i) {
            for (int v = 1; v <= K; ++v) {
                pref0[v] = (pref0[v - 1] + dp0[v]) % MOD;
                pref1[v] = (pref1[v - 1] + dp1[v]) % MOD;
            }
            
            for (int v = 1; v <= K; ++v) {
                next_dp0[v] = (pref1[K] - pref1[v] + MOD) % MOD;
                next_dp1[v] = pref0[v - 1];
            }
            
            std::swap(dp0, next_dp0);
            std::swap(dp1, next_dp1);
        }
        
        long long total_arrays = 0;
        for (int v = 1; v <= K; ++v) {
            total_arrays = (total_arrays + dp0[v] + dp1[v]) % MOD;
        }
        
        return total_arrays;
    }
};
