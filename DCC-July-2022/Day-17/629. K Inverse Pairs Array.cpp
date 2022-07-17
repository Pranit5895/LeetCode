class Solution {
public:
    int kInversePairs(int n, int k) {
        MOD = 1e9 + 7;
        int cache[1001][1001] = {0};
        return (calc(n, k, cache) + MOD - (k != 0 ? calc(n, k - 1, cache) : 0)) % MOD;
    }
    int calc(int n, int k, int cache[][1001]) {
        if (n == 0) return 0;
        if (k == 0) return 1;
        if (cache[n][k]) return cache[n][k];
        int val = (calc(n - 1, k, cache) + MOD - (k >= n ? calc(n - 1, k - n, cache) : 0)) % MOD;
        return cache[n][k] = (calc(n, k - 1, cache) + val) % MOD;
    }
public:
    int MOD;
};
