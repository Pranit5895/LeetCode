//o(n2) DP
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.size();
        if(!n) return "";
        int maxi=0;
        int maxl=1;
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                maxl=2;
                maxi=i;
            }
        for(int l=3;l<=n;l++)
            for(int i=0;i<n-l+1;i++)
            {
                int j=i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=true;
                    maxl=l;
                    maxi=i;
                }
            }
        return s.substr(maxi,maxl);
    }
};
