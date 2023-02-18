class Solution {
	public:
		int solve(vector<int> &nums, int start, int end)
		{
			int prev = 0;
			int curr = nums[start];
			for (int i = start + 1; i <= end; i++)
			{
				int temp = curr;
				curr = max(curr, prev + nums[i]);
				prev = temp;
			}
			return curr;
		}

		int rob(vector<int>& nums) {
			int len = nums.size();
			if (len == 1)
				return nums[0];
			int noHead = solve(nums, 1, len - 1);
			int head = solve(nums, 0, len - 2);
			return max(noHead, head);
		}
};

