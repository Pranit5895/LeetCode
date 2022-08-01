class Solution {
public:
    int uniquePaths(int m, int n) {
        //base case: top boundary and left boundary
        // vector<vector<int>> dp(m, vector(n, 1));
        vector<int> row(n, 1);
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                // dp[i][j] = dp[i-1][j] + dp[i][j-1];
                /*
                row[j] represnets for the value in last row,
                just like dp[i-1][j]
                */
                row[j] = row[j] + row[j-1];
            }
        }
        
        // return dp[m-1][n-1];
        return row[n-1];
    }
};
