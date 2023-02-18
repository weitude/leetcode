class Solution {
	public:
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			unordered_set<int> st1, st2;
			vector<int> ans;
			for (int i : nums1)
				st1.insert(i);
			for (int i : nums2)
			{
				if (st1.count(i) && !st2.count(i))
				{
					ans.push_back(i);
					st2.insert(i);
				}
			}
			return ans;
		}
};

