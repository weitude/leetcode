class Solution {
	public:
		vector<vector<int>> ans;
		vector<int> cache;

		void DFS(vector<int>& nums, int idx)
		{
			if (idx == nums.size())
			{
				ans.push_back(cache);
				return;
			}

			cache.push_back(nums[idx]);
			DFS(nums, idx + 1);
			cache.pop_back();
			DFS(nums, idx + 1);
		}

		vector<vector<int>> subsets(vector<int>& nums) {
			DFS(nums, 0);
			return ans;
		}
};

