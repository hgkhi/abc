class Solution {
public:
    /**
     * Runtime: O(n)
     * Space: O(n)
     */
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] > nums[j]) {
                    result[i]++;
                }
            }
        }
        
        return result;
    }
};
