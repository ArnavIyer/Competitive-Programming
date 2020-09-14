#include <cmath>

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n >m) {
            m = n+m;
            n = m-n;
            m = m-n;
        }
        n-=1;m-=1;
        double ans = 1.0;
        for (int i = 0; i<n; i++) {
            ans*=m+n-i;
            ans/=i+1;
        }
        return int(ans);
    }
};