class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l,r=0,0
        n = len(s)
        st=set()
        ans = 0
        while r<n:
            while l<r and s[r] in st:
                st.remove(s[l])
                l+=1
            st.add(s[r])
            r+=1
            ans = max(ans, r-l)
        return ans