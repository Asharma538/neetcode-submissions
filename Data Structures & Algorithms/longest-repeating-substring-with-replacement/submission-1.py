from collections import deque

class Solution:
    def calc(self, ch, s, k):
        # if k == 0:
        #     j = 0
        #     max_len = 0
        #     while j<len(s):
        #         tmp = 0
        #         while j<len(s) and s[j] == ch:
        #             j+=1
        #             tmp+=1
        #         max_len = max(max_len , tmp)
        #         j+=1
        #     return max_len
        # else:
        q = deque()
        i = 0
        max_len = 0
        for j in range(len(s)):
            if s[j] != ch:
                q.append(j)
                if len(q) > k:
                    i = q.popleft()+1
            max_len = max(max_len , j - i + 1)
        return max_len


    def characterReplacement(self, s: str, k: int) -> int:
        st = set()
        for i in s:
            st.add(i)
        
        ans = 0
        for ch in st:
            ans = max(ans, self.calc(ch, s, k))
        return ans