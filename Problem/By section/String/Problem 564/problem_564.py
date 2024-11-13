class Solution:
    # Time: O(n) Space: O(1)
    def nearestPalindromic(self, n: str) -> str:
        original_num = int(n)
        length = len(n)
        is_even = (length % 2) == 0
        mid_point = (length // 2) + (1 if not is_even else 0)
        first_half = n[:mid_point]
        num = int(first_half)

        # e.g 12345
        # 12321
        # 12221
        # 12421
        # 9999
        # 10001
        possibilities = [
            self.generate_palindrom(num, is_even),
            self.generate_palindrom(num + 1, is_even),
            self.generate_palindrom(num - 1, is_even),
            10 ** (length - 1) - 1,
            10 ** (length) + 1,
        ]

        result_seq = filter(
            lambda x: x != original_num, 
            sorted(possibilities, key=lambda x: (abs(x - original_num), x))
        )
        
        return str(next(result_seq))

    def generate_palindrom(self, num: int, is_even: bool) -> int:
        result = num

        if not is_even:
            num //= 10
        
        while num > 0:
            result = result * 10 + (num % 10)
            num //= 10
        
        return result
        