class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> a;
        for (int i = 0; i<nums.size(); i++) {
            if (a.count(nums[i])) return nums[i];
            a.insert(nums[i]);
        }
        return 0;
    }
};