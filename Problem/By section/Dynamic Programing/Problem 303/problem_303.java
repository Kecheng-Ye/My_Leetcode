class NumArray{
    // sums[i] = the sum from nums[0] to nums[i - 1]
    private int[] sums;

    // Time: O(n), Space:O(n)
    public NumArray(int[] nums) {
        sums = new int[nums.length + 1];
        for (int i = 1; i <= nums.length; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
    }

    //sumRange(i, j) =  sum[j + 1] - sum[i]
    public int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
}