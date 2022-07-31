class NumArray {
    private int[] tree, nums;
    public NumArray(int[] nums) {
        this.tree = new int[nums.length + 1];
        this.nums = nums;
        for (int i = 0; i < nums.length; i++) {
            int tmp = nums[i];
            nums[i] = 0;
            update(i, tmp);
        }
    }
    public void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        index++;
        while (index < tree.length) {
            tree[index] += diff;
            index += (index & -index);
        }
    }
    public int sumRange(int left, int right) {
        return (left == 0)? sum(right) : (sum(right) - sum(left-1));
    }
    private int sum(int index) {
        index++;
        int ret = 0;
        while (index > 0) {
            ret += tree[index];
            index &= (index - 1);
        }
        return ret;
    }
}
