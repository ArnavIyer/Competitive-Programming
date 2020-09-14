class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        vector<int> fwd(n);
        vector<int> bkwd(n);
        int prod = 1;
        for (int i = 0; i<n; i++) {
            prod *= nums[i];
            fwd[i] = prod;
        }
        prod = 1;
        for (int i = n-1; i>=0; i--) {
            prod *= nums[i];
            bkwd[i] = prod;
        }
        for (int i = 0; i<n; i++) {
            if (i == 0) ans[i] = bkwd[1];
            else if (i == n-1) ans[i] = fwd[n-2];
            else ans[i] = bkwd[i+1]*fwd[i-1];
        }
        return ans;
    }
};
