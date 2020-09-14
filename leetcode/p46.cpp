class Solution {
public:
    void perm(vector<vector<int>>& answer, int end, int count, vector<int> nums) {
        if (count == end) return;
        int ansize = answer.size();
        for (int i = 0; i<ansize; i++) {
            for (int j = 0; j<answer[i].size(); j++) {
                vector<int> tem = answer[i];
                tem.insert(tem.begin()+j, nums[count]);
                answer.push_back(tem);
            }
            answer[i].push_back(nums[count]);
        }
        perm(answer, end, count+1,nums);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        t.push_back(nums[0]);
        ans.push_back(t);
        perm(ans,nums.size(), 1,nums);
        return ans;
    }
};