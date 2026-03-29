class Solution:
    def trap(self, h: List[int]) -> int:
        n = len(h)
        p,s = [h[0]],[h[n-1]]

        for i in range(1,n):
            if p[i-1]>h[i]:
                p.append(p[i-1])
            else:
                p.append(h[i])
            
            if s[i-1]>h[n-i-1]:
                s.append(s[i-1])
            else:
                s.append(h[n-i-1])
        s.reverse()
        ans = 0
        for i in range(n):
            ans += min(s[i],p[i])-h[i]
        return ans