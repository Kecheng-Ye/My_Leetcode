from math import inf
from typing import List


class Solution:
    # Time: O(2^n) Space: O(n)
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = set()
        perm = []
        
        def dfs(i, prev):
            if i == len(nums):
                if len(perm) >= 2:
                    res.add(tuple(perm))
                return
            
            # choose to skip this number
            dfs(i+1, prev)
            
            # choose to include this number if possible
            if nums[i] >= prev:
                perm.append(nums[i])
                dfs(i+1, nums[i])
                perm.pop()
        
        dfs(0, -inf)
        return list(res)