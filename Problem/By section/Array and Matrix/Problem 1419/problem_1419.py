class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        next_letter = {
            'c': 'r',
            'r': 'o',
            'o': 'a',
            'a': 'k',
            'k': 'c'
        }

        need = {
            'c': 1,
            'r': 0,
            'o': 0,
            'a': 0,
            'k': 0
        }

        result = 1

        for char in croakOfFrogs:
            if need[char] == 0:
                if char == 'c':
                    result += 1
                    need['r'] += 1
                else:
                    return -1
            else:
                need[char] -= 1
                need[next_letter[char]] += 1

        for char in need:
            if char != 'c' and need[char] != 0:
                return -1

        return result
