class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        int median = medianVal(nums);
        for (int i = 0; i < n; ++i) {
            result += abs(nums[i] - median);
        }
        return result;
    }
private:
    inline void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int medianVal(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid = n / 2;
        while (true) {
            int k = left;
            int temp = rand() % (right - left + 1) + left;
            swap(nums[right], nums[temp]);
            for (int i = left; i < right; ++i) {
                if (nums[i] < nums[right]) {
                    swap(nums[i], nums[k++]);
                }
            }
            swap(nums[right], nums[k]);
            if (k == mid) {
                return nums[k];
            }
            else if (k < mid) {
                left = k + 1;
            }
            else {
                right = k - 1;
            }
        }
    }
};
