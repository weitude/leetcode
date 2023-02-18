class Solution {
	public:
		vector<int> dp;
		int len;

		int LIS (vector<int> &nums, int idx)
		{
			if (idx == 0)
				return 1;
			if (dp[idx] != -1)
				return dp[idx];
			int ans = 1;
			for (int i = 0; i < idx; i++)
			{
				if (nums[idx] > nums[i])
				{
					int temp = LIS(nums, i) + 1;
					if (ans < temp)
						ans = temp;
				}
			}
			dp[idx] = ans;
			return dp[idx];
		}

		int lengthOfLIS(vector<int>& nums) {
			len = nums.size();
			dp.resize(len, -1);
			int ans = 0;
			for (int i = 0; i < len; i++)
			{
				int ret = LIS(nums, i);
				if (ans < ret)
					ans = ret;
			}
			return ans;
		}
};

