class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ans = len(s)+1
        anss = [-1,-1]
        dt = {}
        for ch in t:
            if ch not in dt: dt[ch]=1
            else: dt[ch]+=1
        
        i = 0
        ds = {}
        for j in range(len(s)):
            if s[j] in ds:
                ds[s[j]]+=1
            else:
                ds[s[j]]=1
            
            while i<j and (s[i] not in dt or dt[s[i]]<ds[s[i]]):
                ds[s[i]]-=1
                i+=1
            
            # print(s[i:j+1], ds, end=" ")
            potn = True
            for ch in dt:
                if ch not in ds or ds[ch]<dt[ch]:
                    potn = False
            if potn:
                if ans>j-i+1:
                    ans = j-i+1
                    anss = [i,j]
            # print(s[anss[0]:anss[1]+1])
        return s[anss[0]:anss[1]+1]