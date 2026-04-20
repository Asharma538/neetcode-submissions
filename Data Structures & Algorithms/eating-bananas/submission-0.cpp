class Solution {
public:
    int calc_h(vector<int>& piles, int k){
        int h = 0;
        for(auto i : piles){
            h += i/k;
            if (i%k!=0) h+=1;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = 1e9;
        int l = 1;
        while(l<r){
            int mid = (l+r)/2;
            if (calc_h(piles, mid) <= h){
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return r;
    }
};
