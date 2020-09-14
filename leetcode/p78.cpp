class Solution {
public:
    void subset(vector<vector<int>>& answer, int count, int end, vector<int> nums) {
        if (count == end) return;
        int ansize = answer.size();
        for (int i = 0; i<ansize; i++) {
            vector<int> temp2 = answer[i];
            temp2.push_back(nums[count]);
            answer.push_back(temp2);
        }
        subset(answer, count+1, end, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        temp.push_back(nums[0]);
        ans.push_back(temp);
        subset(ans, 1, nums.size(), nums);
        return ans;
    }
};
