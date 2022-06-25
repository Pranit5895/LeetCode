class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int pos = -1;
        for(int i = 0; i+1 < n; ++i){
            if(nums[i] > nums[i+1]){
                if(pos == -1){
                    pos = i;
                }else{
                    return false;
                }
            }
        }
        return (pos == -1) || (pos == 0) || (pos+1 == n-1) || (nums[pos-1] <= nums[pos+1]) || (nums[pos] <= nums[pos+2]);
    }
};
