class Solution:
    # Time: O(n) Space: O(1)
    def minPatches(self, nums, n):
        miss = 1
        patches = 0
        i = 0

        while miss <= n:
            # If the current number in `nums` is within our range, use it
            if i < len(nums) and nums[i] <= miss:
                miss += nums[i]
                i += 1
            else:
                # Otherwise, add a patch (the current `miss`)
                miss += miss
                patches += 1

        return patches