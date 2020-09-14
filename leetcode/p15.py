class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp(3);
        int n = nums.size();
        //bool zero3 = false;
        for (int c = 0; c<n-2; c++) {
            int i = c+1; 
            int j = n-1;
            while (i<j) {
                if (nums[i] +nums[j] + nums[c] == 0) { 
                    temp[0] = nums[c];
                    temp[1] = nums[i];
                    temp[2] = nums[j];
                    ans.push_back(temp);
                    
                    while ( i<j && nums[i] == temp[1]) i++;
                    while ( i<j && nums[j] == temp[2]) j--;
                }
                else if (nums[i]+nums[j]+nums[c] > 0) j--;
                else i++;
            }
            while (c< n-2 && nums[c]==nums[c+1]) c++;
        }
        return ans;
    }
};