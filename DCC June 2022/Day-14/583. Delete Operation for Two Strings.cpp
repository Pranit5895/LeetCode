class Solution {
public:
    int minDistance(string word1, string word2) {
        int i,j,m=word1.length(),n=word2.length();
        int dp[m+1][n+1];
        for(i=0;i<=m;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==0 ||j==0)
                    dp[i][j] = 0;
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int same = dp[m][n];
        return m+n-2*same;
    }
};
