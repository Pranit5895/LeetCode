class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        int ans = 0;
        int dp_is1_js1, dp_is1_j;
        
        for(int i = 0; i < n; i++){
            /*
            when j is 0, this is meaningless, 
            reset when meeting a new row
            */
            dp_is1_js1 = INT_MAX;
            for(int j = 0; j <= i; j++){
                dp_is1_j = dp[j];
                if(i == 0){
                    dp[j] = triangle[i][j];
                }else{
                    dp[j] = min(j > 0 ? dp_is1_js1 : INT_MAX, 
                                j < i ? dp[j] : INT_MAX) + 
                                triangle[i][j];
                }
                dp_is1_js1 = dp_is1_j;
            }
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
