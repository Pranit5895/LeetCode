class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1+sqrt5)/2, n+1) - pow((1-sqrt5)/2, n+1);
        return (int)(fibn/sqrt5);
    }
};