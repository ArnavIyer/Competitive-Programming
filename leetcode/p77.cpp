class Solution {
public:
    void comb(vector<int>& temp, vector<vector<int>>& answer, int count, int& k, vector<int>& nums) {
        if (temp.size() == k) {
            answer.push_back(temp);
            return;
        }
        if (count == nums.size())return;
        temp.push_back(nums[count]);
        comb(temp, answer,count+1,k,nums);
        temp.pop_back();
        comb(temp,answer,count+1, k, nums);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        for (int i = 1; i<n+1; i++) 
            nums.push_back(i);
        vector<int> tem;
        comb(tem, ans, 0, k, nums);
        return ans;
    }
};