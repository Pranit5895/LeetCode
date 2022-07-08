class Solution {
public:
    int MAX = 1e6+1;
    int m, n, target;
    vector<vector<vector<int>>> memo;
    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int start, int t, int prevColor){
        if(t < 0 || t > m-start){
            return MAX;
        }else if(start == m){
            return (t == 0) ? 0 : MAX;
        }else if(memo[start][t][prevColor+1] != 0){
            return memo[start][t][prevColor+1];
        }else if(houses[start] != 0){
            memo[start][t][prevColor+1] = dfs(houses, cost, start+1, t - (houses[start] != prevColor), houses[start]);
            return memo[start][t][prevColor+1];
        }else{
            int ans = MAX;
            for(int color = 1; color <= n; color++){
                ans = min(ans, cost[start][color-1] + dfs(houses, cost, start+1, t - (color != prevColor), color));
            }
            return memo[start][t][prevColor+1] = ans;
        }
    };
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->m = m;
        this->n = n;
        this->target = target;
        
        memo = vector<vector<vector<int>>>(m, vector<vector<int>>(target+1, vector<int>(n+2, 0)));
        
        int ans = dfs(houses, cost, 0, target, -1);
        return (ans >= MAX) ? -1 : ans;
    }
};
