class Solution {
public:  
    vector<int> topKFrequent(vector<int>& nums, int& k) {
        map<int,int> mep;
        priority_queue<pair<int,int>> dog;
        vector<int> ans;
        for (int i = 0; i<nums.size(); i++) {
            if (mep.count(nums[i]))
                mep[nums[i]] += 1;
            else mep[nums[i]] = 1;
        }
        map<int,int>::iterator it;
        for (it = mep.begin(); it != mep.end(); it++) {
            dog.push(make_pair(it->second, it->first));
        }
        for (int i = 0; i<k; i++) {
            ans.push_back(dog.top().second);
            dog.pop();
        }
        return ans;
    }
};