class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        d = {
            ']':'[',
            '}':'{',
            ')':'(',
        }

        for i in s:
            if i in d:
                if len(stk)>0 and stk[-1]==d[i]:
                    stk.pop()
                    continue
                else:
                    return False
            else:
                stk.append(i)
        return True if len(stk)==0 else False