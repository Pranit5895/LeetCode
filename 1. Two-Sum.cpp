//sort + two pointer
//Runtime: 8 ms, faster than 99.93% of C++ online submissions for Two Sum.
//Memory Usage: 9.5 MB, less than 70.01% of C++ online submissions for Two Sum.
//time: O(NlogN), space: O(N)
class Solution {
public:
    template <typename T>
    vector<int> sort_indexes(const vector<T> &v) {

      // initialize original index locations
      vector<int> idx(v.size());
      iota(idx.begin(), idx.end(), 0);

      // sort indexes based on comparing values in v
      sort(idx.begin(), idx.end(),
           [&v](int i1, int i2) {return v[i1] < v[i2];});

      return idx;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ixs = sort_indexes(nums);
        
        int i = 0, j = nums.size()-1;
        
        while(i < j){
            int ix1 = ixs[i], ix2 = ixs[j];
            if(nums[ix1] + nums[ix2] == target){
                return vector<int> {ix1, ix2};
            }else if(nums[ix1] + nums[ix2] < target){
                i++;
            }else{
                j--;
            }
        }
        return vector<int>();
    }
};