class Solution:
    def decodeString(self, s: str) -> str:
      
      result = ""
      context = ""
      bracket_dict = {'[' : 0 , ']' : 0}
      num = 0
      
      for letter in s:
        # print(f"letter = {letter} , bracket_dict = '[' : {bracket_dict['[']} , ']' : {bracket_dict[']']} , result = {result}")
        if letter == '[':
          bracket_dict['['] += 1
        elif letter == ']':
          bracket_dict[']'] += 1
        if (not bracket_dict['['] and not bracket_dict[']']) and'0' <= letter <= '9':
          
          num = int(str(num) + letter)
          
        elif (not bracket_dict['['] and not bracket_dict[']']) and ('A' <= letter <= 'Z'or 'a' <= letter <= 'z'):
          result += letter
        elif (bracket_dict['['] or bracket_dict[']']) and (bracket_dict['['] > bracket_dict[']']):
          if letter == '[' and bracket_dict['['] == 1:
            continue
          else:
            context += letter
        elif (bracket_dict['['] or bracket_dict[']']) and (bracket_dict['['] == bracket_dict[']']):
          result += self.decodeString(context)*num
          context = ""
          bracket_dict = {'[' : 0 , ']' : 0}
          num = 0
      return result
s = Solution()
print(s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef"))
        
          
          