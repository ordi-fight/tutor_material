from typing import List


class Solution:
    def __init__(self):
        self.phone = [None, None, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        self.result = []

    def recursion(self, digits: str, curStr):
        if digits == "":
            self.result.append(curStr)
            return

        number = int(digits[0])
        chars = self.phone[number]

        for char in chars:
            self.recursion(digits[1:], curStr + char)
        return

    def letterCombinations(self, digits: str) -> List[str]:
        self.recursion(digits, "")
        return self.result