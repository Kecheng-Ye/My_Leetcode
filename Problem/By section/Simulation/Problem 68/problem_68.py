from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = []

        cur_line_words = []
        cur_line_len = 0
        
        for word in words:
            word_len = len(word)
            
            if cur_line_len + word_len > maxWidth:
                result.append(self.format_one_line(cur_line_words, maxWidth))
                cur_line_words = []
                cur_line_len = 0

            cur_line_words.append(word)
            cur_line_len += word_len + 1

        result.append(self.format_last_line(cur_line_words, maxWidth))

        return result

    def format_one_line(self, words: List[str], maxWidth: int) -> str:
        if len(words) == 1:
            return words[0] + " " * (maxWidth - len(words[0]))

        result = ""
        total_len = sum(len(word) for word in words)
        total_space_len = maxWidth - total_len
        num_of_space = (len(words) - 1)

        space_len = (total_space_len // num_of_space)
        remainder = total_space_len % num_of_space


        for i in range(len(words)):
            result += words[i]
            if i == len(words) - 1:
                break
            
            result += " " * (space_len)
            
            if remainder:
                result += " "
                remainder -= 1
        
        assert len(result) == maxWidth, f"{result} has wrong len: {len(result)}, expected: {maxWidth}"
        return result

    def format_last_line(self, words: List[str], maxWidth: int) -> str:
        result = " ".join(words)
        return result + " " * (maxWidth - len(result))