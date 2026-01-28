from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        path = []

        def rec(depth, curMaxNum):
            if depth == k:
                result.append(path.copy())
                return
            
            for number in range(curMaxNum + 1, n - k + depth + 2):
                path.append(number)
                rec(depth + 1, number)
                path.pop()
        rec(0, 0)

        return result

