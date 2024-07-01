class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int n = s.size();
			int l = 0;
			unordered_map<char, int> mp;
			int mx = 0;
			for (int i = 0; i < n; i++) {
				if (mp.find(s[i]) != mp.end()) {
					for (int j = l; j < mp[s[i]]; j++)
						mp.erase(s[j]);
					l = mp[s[i]] + 1;
				}
				mp[s[i]] = i;
				if (mx < i - l + 1)
					mx = i - l + 1;
			}
			return mx;
		}
};

