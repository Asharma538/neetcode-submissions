class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        d = {}
        for i in s1:
            if i in d: d[i]+=1
            else: d[i]=1
        
        d2 = {}
        for i in range(len(s2)):
            if s2[i] in d2: d2[s2[i]]+=1
            else: d2[s2[i]]=1

            if i>=len(s1)-1:
                ans = True
                if i>=len(s1): d2[s2[i-len(s1)]]-=1
                for k in d2:
                    if k not in d:
                        if d2[k]!=0:
                            ans = False
                            break
                    elif d[k]!=d2[k]:
                        ans = False
                        break
                if ans: return True
            print(d,d2)
        return False