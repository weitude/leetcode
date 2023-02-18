class Solution {
	public:
		vector<int> dp;

		int solve(vector<int> &nums, int idx)
		{
			if (idx >= nums.size())
				return 0;
			if (dp[idx] != -1)
				return dp[idx];
			int take = nums[idx] + solve(nums, idx + 2);
			int noTake = solve(nums, idx + 1);
			dp[idx] = max(take, noTake);
			return dp[idx];
		}

		int rob(vector<int>& nums) {
			dp.resize(nums.size(), -1);
			return solve(nums, 0);
		}
};

