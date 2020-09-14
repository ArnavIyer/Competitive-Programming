class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int& target) {
        vector<int> a;
        map<int,int> b;
        for (int i = 0; i<nums.size(); i++) {
            if (b.count(target-nums[i])) {
                a.push_back(i);
                a.push_back(b[target-nums[i]]);
                return a;
            }
            b[nums[i]] = i;
        }
        return a;
    }
};