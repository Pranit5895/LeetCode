class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        if(n <= 1) return n;
        
        //up: how many transitions are going up
        int up = 0;
        //down: how many transitions are going down
        int down = 0;
        //record the mountain peak
        int peak = 0;
        
        //candy for 0th child?
        int ans = 1;
        
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                ++up;
                peak = up;
                down = 0;
                //the mountain's foot must be >= 1
                ans += (1+up);
            }else if(ratings[i] == ratings[i-1]){
                up = down = peak = 0;
                ans += 1;
            }else{
                //ratings[i] < ratings[i-1]
                ++down;
                up = 0;
                ans += down;
                if(peak < down){
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};

