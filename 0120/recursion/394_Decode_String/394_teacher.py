class Solution:
    def __init__(self):
        self.idx = 0
    
    def decodeString(self, s: str) -> str:
        result = ""
        count = 0
        
        while self.idx < len(s):
            char = s[self.idx]
            if char.isdigit():
                count = 10 * count + int(char)
                self.idx += 1
            
            elif char == '[':
                self.idx += 1
                result += count * self.decodeString(s)
                self.idx += 1
                count = 0
            
            elif char == ']':
                return result
            
            else:
                result += char
                self.idx += 1
        
        return result

