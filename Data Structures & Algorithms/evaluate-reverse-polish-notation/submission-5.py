class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stk = []
        sym = "+-*/"
        for i in tokens:
            if i in sym:
                a = stk.pop()
                b = stk.pop()
                c = b
                if i == "+":
                    c += a
                elif i == "-":
                    c -= a
                elif i == "*":
                    c *= a
                else:
                    c /= a
                    # if c<0 and int(c)!=c:
                    #     c+=1
                    c=int(c)
                stk.append(c)
            else:
                stk.append(int(i))
            print(stk)
        return stk.pop()