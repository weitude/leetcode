class Solution {
	public:
		int subarraySum(vector<int>& nums, int k) {
			unordered_map<int, int> umap;
			int sum = 0, ans = 0;
			umap[0] = 1;
			for (int num : nums)
			{
				sum += num;
				int target = sum - k;
				ans += umap[target];
				umap[sum]++;
			}
			return ans;
		}
};

