class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return x;
        if(x == -1) return n % 2 ? -1 : 1;
        if(x < 1 && n == INT_MAX || n == INT_MIN) return 0;
        double res=1;
        if(n < 0) x = 1/x, n = -n;
        while(n > 0){
            res = res * x;
            n--;
        }
        return res;
    }
};
