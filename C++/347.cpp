class Solution {
	public:
		vector<int> topKFrequent(vector<int>& nums, int k) {
			unordered_map<int, int> umap;
			multimap<int, int, greater<int>> dict;
			for(int num : nums)
				umap[num]++;
			for (auto p : umap)
				dict.insert({p.second, p.first});

			int idx = 0;
			vector<int> ans;
			for (auto p : dict)
			{
				ans.push_back(p.second);
				idx++;
				if (idx == k)
					break;
			}
			return ans;
		}
};

