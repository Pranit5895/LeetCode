//Runtime: 160 ms, faster than 16.92% of C++ online submissions for Remove Duplicates from Sorted Array.
//Memory Usage: 10 MB, less than 99.23% of C++ online submissions for Remove Duplicates from Sorted Array.


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int last = nums[0];
        int i = 1;
        while(i < nums.size()){
            if(nums[i] == last){
                nums.erase(nums.begin()+i);
            }else{
                last = nums[i];
                i++;
            }
        }
        return nums.size();
    }
};
