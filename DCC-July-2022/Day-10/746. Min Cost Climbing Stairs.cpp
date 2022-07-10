class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int steps = cost.size();
        int prevPrev = cost[0];
        int prev = min(cost[0] + cost[1], cost[1]);
        for (int i = 2; i < steps; i++) {
            int curr = cost[i] + min(prev, prevPrev);
            prevPrev = prev;
            prev = curr;
        }
        return min(prev, prevPrev);
    }
};
