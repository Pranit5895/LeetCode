class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> snums(nums.begin(), nums.end());
        
        int maxStreak = 0;
        
        for(const int num : snums){
            if(snums.find(num-1) == snums.end()){
                //that means num is the head of its group
                int cur = num;
                while(snums.find(cur+1) != snums.end()){
                    ++cur;
                }
                
                //[num...cur] is a group
                maxStreak = max(maxStreak, cur-num+1);
            }
        }
        
        return maxStreak;
    }
};
