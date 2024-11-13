class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 1:
            return k
        elif n == 2:
            return k * k

        same = k  # Ways to paint the first post
        diff = k * (k - 1)  # Ways to paint two posts with different colors
        total = same + diff

        for i in range(3, n + 1):
            new_same = diff  # Current post same as previous
            new_diff = total * (k - 1)  # Current post different from previous
            total = new_same + new_diff
            same, diff = new_same, new_diff

        return total
        