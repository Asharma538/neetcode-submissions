class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) return n;
        int a = 1;
        int b = 2;
        while(n>2){
            int t = a+b;
            a = b;
            b = t;
            n--;
        }

        return b;
    }
};
