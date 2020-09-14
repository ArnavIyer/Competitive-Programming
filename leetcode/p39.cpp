class Solution {
public:
    void recurse(vector<vector<int>>& ans, vector<int> curr, int& target, int currsum, int currindex, vector<int>& nums) {
        if (currsum > target) {
            return;
        }
        else if (currsum == target) {
            ans.push_back(curr);
            return;
        }
        for (int i = currindex; i<nums.size(); i++) {
            vector<int> nume = curr;
            nume.push_back(nums[i]);
            int newsum = currsum + nums[i];
            recurse(ans, nume, target, newsum, i, nums);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> a;
        vector<int> curr;
        recurse(a,curr,target,0,0,candidates);
        return a;
    }
};