class Solution {
public:
    int numWays(string s) {
        int onecount = 0;
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == '1') {
                onecount ++;
            }
        }
        if (onecount == 0) {
            return ((s.size()-1)*(s.size()-2)/2) % 1000000007;
        }
        if (onecount%3!=0) return 0;
        onecount /=3;
        vector<long long> parts = {0,0};
        int currones = 0;
        for (int i = 0;i<s.size(); i++) {
            if (s[i] == '1') currones++;
            if (currones == onecount) {
                parts[0]++;
            }
            else if (currones == onecount*2) {
                parts[1]++;
            }
            else if (currones > onecount*2) break;
        }
        return parts[0]*parts[1] % 1000000007;
    }
};