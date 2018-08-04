class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_global = nums[0];
        int max_local = max_global;
        
        for (int i = 1; i < nums.size(); ++i) {
            max_local = max(max_local + nums[i], nums[i]);
            max_global = max(max_global, max_local);
        }
        
        return max_global;
    }
};
