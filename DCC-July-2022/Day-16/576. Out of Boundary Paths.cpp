class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int MOD = 1e9+7;
        //how many possible ways to go to (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //take 0 moves
        dp[i][j] = 1;
        
        //how many possible ways to cross the boundary
        int ans = 0;
        
        //take N moves
        while(N-- > 0){
            vector<vector<int>> tmp(m, vector<int>(n, 0));
            
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    //cross boundary, update ans
                    if(i == 0)   ans = (ans+dp[i][j])%MOD;
                    if(i == m-1) ans = (ans+dp[i][j])%MOD;
                    if(j == 0)   ans = (ans+dp[i][j])%MOD;
                    if(j == n-1) ans = (ans+dp[i][j])%MOD;
                    
                    //update (i,j)'s count, from 4 directions
                    int a = (i>0) ? dp[i-1][j] : 0;
                    int b = (i<m-1) ? dp[i+1][j] : 0;
                    int c = (j>0) ? dp[i][j-1] : 0;
                    int d = (j<n-1) ? dp[i][j+1] : 0;
                    
                    tmp[i][j] = (((a+b)%MOD + c)%MOD + d)%MOD;
                }
            }
            
            swap(dp, tmp);
        }
        
        return ans;
    }
};
