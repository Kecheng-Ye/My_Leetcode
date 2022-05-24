class Solution:
    def minOperationsToFlip(self, expression: str) -> int:
        # This calculates expression 'left' ('&' or '|') 'right', and minimum cost to flip
        # op: None or '&' or '|'
        # left, right: (expression_value, min_flip)
        # return: (expression_value, min_flip)
        def calculate(op: Optional[str], left: Tuple[bool, int], right: Tuple[bool, int]) -> Tuple[bool, int]:
            if not op:
                return right
            if op == '|':
                if left[0] and right[0]:
                    # Change '|' to '&', and flip left or right expression value True to False
                    return (True, min(left[1], right[1]) + 1)
                if left[0] or right[0]:
                    # Change '|' to '&'
                    return (True, 1)
                # Flip left or right expression value False to True
                return (False, min(left[1], right[1]))
            
            if not left[0] and not right[0]:
                # Change '&' to '|', and flip left or right expression value False to True
                return (False, min(left[1], right[1]) + 1)
            if not left[0] or not right[0]:
                # Change '&' to '|'
                return (False, 1)
            # Flip left or right expression value False to True
            return (True, min(left[1], right[1]))

        st = []
        op, cur = None, (True, -1)
        for ch in expression:
            if ch.isdigit():
                cur = calculate(op, cur, (ch == '1', 1))
            elif ch == '&' or ch == '|':
                op = ch
            elif ch == '(':
                st.append((op, cur))
                op = None
            else:
                op, prev = st.pop()
                cur = calculate(op, prev, cur)
        return cur[1]
        