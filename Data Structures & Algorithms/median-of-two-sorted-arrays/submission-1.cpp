class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n = nums1.size(), m = nums2.size();

        int l=0, r=n-1;
        int t = n+m;
        int th = t/2;
        
        int times = 50;
        while (times--){
            int i = (l+r)/2;
            if (r<0) i=-1;
            int j = th - i - 2;
            cout<<l<<' '<<r<<'|'<<i<<' '<<j<<'\n';

            int aleft;
            if (i>=0) aleft = nums1[i]; else aleft = -1e9;

            int aright;
            if (i+1 < n) aright = nums1[i+1]; else aright = 1e9;

            int bleft;
            if (j>=0) bleft = nums2[j]; else bleft = -1e9;

            int bright;
            if (j+1 < m) bright = nums2[j+1]; else bright = 1e9;

            cout<<aleft<<' '<<aright<<'|'<<bleft<<' '<<bright<<'\n';
            if (aleft <= bright and bleft <= aright){
                if (t%2) return min(aright, bright);
                return ((double)max(aleft,bleft)+min(aright,bright))/2.0;
            } else if (aleft > bright){
                r=i-1;
            } else {
                l=i+1;
            }
        }
        return 0;
    }
};
