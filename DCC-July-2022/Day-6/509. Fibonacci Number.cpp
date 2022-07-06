class Solution {
public:
    int fib(int n) {
        
        
         ios::sync_with_stdio(0);
        cin.tie(0);
        
        int *dp = new int[n+1];
        
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        dp[0]=0;
        dp[1] = 1;
       // dp[2] = 2;
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n];
        
    }
};
