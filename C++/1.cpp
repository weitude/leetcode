class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> mp;
			int n = nums.size();
			for (int i = 0; i < n; i++) {
				int comp = target - nums[i];
				auto search = mp.find(comp);
				if (search != mp.end()) {
					return {i, search->second};
				} else {
					mp[nums[i]] = i;
				}
			}
			return {-1, -1};
		}
};

