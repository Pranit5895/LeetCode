class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        int m = s1.size(), n = s2.size();
        
        /*
        dp[i][j] depends on dp[i-1][j] and dp[i][j-1]
        for dp[i-1][j], since we visit i from 0 to m, so it's safe
        for dp[i][j-1], since we visit j from 0 to n, so it's safe
        */
        vector<bool> dp(n+1, false);
        
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                if(i == 0 && j == 0){
                    dp[j] = true;
                }else if(i == 0){
                    dp[j] = (s2[j-1] == s3[i+j-1]) && dp[j-1];
                }else if(j == 0){
                    dp[j] = (s1[i-1] == s3[i+j-1]) && dp[j];
                }else{
                    dp[j] = (s1[i-1] == s3[i+j-1] && dp[j])
                     || (s2[j-1] == s3[i+j-1] && dp[j-1]);
                }
            }
        }
        
        return dp[n];
    }
};
