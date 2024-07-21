class Solution(object):
    # Time: O(log(n)), Space: O(1)
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n = len(nums)

        if n == 1:
            return nums[0]

        left, right = 0, n

        while left < right:
            mid = left + (right - left) // 2

            if self.is_target_number(nums, mid):
                return nums[mid]
            else:
                if nums[mid] == nums[mid + 1]:
                    if (right - mid) % 2 == 0:
                        right = mid
                    else:
                        left = mid + 2
                elif nums[mid] == nums[mid - 1]:
                    if (mid - 2 - left + 1) % 2 == 0:
                        left = mid + 1
                    else:
                        right = mid - 1
                else:
                    assert False
        

        return nums[left]



    def is_target_number(self, nums, idx):
        if idx == 0 and nums[idx] != nums[idx + 1]:
            return True
        
        if (idx == len(nums) - 1) and nums[idx] != nums[idx - 1]:
            return True

        return nums[idx] != nums[idx - 1] and nums[idx] != nums[idx + 1]

if __name__ == "__main__":
    solution = Solution()
    print(solution.singleNonDuplicate([3,3,7,7,11,11,12]))