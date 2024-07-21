from typing import List


class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        
        return "".join(f"{len(_str)}-{_str}" for _str in strs) 
        

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        if not s:
            return ""

        n = len(s)
        i = 0
        result = []

        while i < n:
            start = i
            while s[i] != '-':
                i += 1
            curr_word_len = int(s[start : i])
            i += 1 # skip '-'
            result.append(s[i: i + curr_word_len])
            i += curr_word_len
        
        return result


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))