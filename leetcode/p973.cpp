class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<float,int>> a;
        vector<vector<int>> ans;
        for (int i = 0; i<points.size(); i++) {
            a.push_back(make_pair(hypot(points[i][0],points[i][1]),i));
            cout << hypot(points[i][0],points[i][1]) << endl;
        }
        sort(a.begin(),a.end());
        for (int i = 0; i<K; i++) {
            ans.push_back(points[a[i].second]);
        }
        return ans;
    }
};