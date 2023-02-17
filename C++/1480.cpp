class Solution {
    public:
        vector<int> runningSum(vector<int>& nums) {
            vector<int> ans;
            int temp = 0, len = nums.size();
            for (int i = 0 ; i < len ;i++)
            {
                temp += nums[i];
                ans.push_back(temp);
            }
            return ans;
        }
};

