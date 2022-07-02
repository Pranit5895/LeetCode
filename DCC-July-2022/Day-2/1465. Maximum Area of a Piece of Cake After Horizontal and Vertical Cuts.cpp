class Solution {
public:
    long long moduloMultiplication(long long a, 
                            long long b, 
                            long long mod) 
    { 
        long long res = 0; 
        a %= mod; 

        while (b) 
        { 
            if (b & 1) 
                res = (res + a) % mod; 
 
            a = (2 * a) % mod; 

            b >>= 1; // b = b / 2 
        } 

        return res; 
    } 

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxh = INT_MIN, maxw = INT_MIN;
        
        for(int i = 0; i < horizontalCuts.size(); i++){
            maxh = max(maxh, horizontalCuts[i] - ((i > 0) ? horizontalCuts[i-1] : 0));
        }
        maxh = max(maxh, h - horizontalCuts[horizontalCuts.size()-1]);
        
        for(int i = 0; i < verticalCuts.size(); i++){
            maxw = max(maxw, verticalCuts[i] - ((i > 0) ? verticalCuts[i-1] : 0));
        }
        maxw = max(maxw, w - verticalCuts[verticalCuts.size()-1]);
        
        return moduloMultiplication(maxh, maxw, 1e9+7);
    }
};
