class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> a;
        a.push_back(0);
        int count = 1;
        int last = -1;
        for (int i = T.size()-2;i>-1; i--) {
            if (T[i] < T[i+1]) {
                a.push_back(1);
            } else if (T[i] == T[i+1]) {
                int push = (*(a.end()-1) == 0) ? 0 : 1+*(a.end()-1);
                a.push_back(push);
            } else {
                int ct = 0;
                for (int j = i+1; j < T.size(); j++) {
                    ct++;
                    if (T[i] < T[j]) break;
                    if (j == T.size()-1) ct = 0;
                }
                a.push_back(ct);
            }
        }
        reverse(a.begin(), a.end());
        return a;
    }
};