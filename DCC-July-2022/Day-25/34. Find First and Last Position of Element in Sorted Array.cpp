class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }
        vector<int> res;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[left] == target) {
            res.push_back(left);
        } else if (nums[right] == target) {
            res.push_back(right);
        } else {
            return vector<int>{-1, -1};
        }
        
        left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[right] == target) {
            res.push_back(right);
        } else if (nums[left] == target) {
            res.push_back(left);
        } 
        return res;
    }
};
