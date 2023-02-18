class Solution {
	public:
		int numUniqueEmails(vector<string>& emails) {
			unordered_map<string, int> umap;
			for (string s : emails)
			{
				string email = "";
				int idx = 0, len = s.length();
				for (; idx < len; idx++)
				{
					if (s[idx] == '+' || s[idx] == '@')
						break;
					if (s[idx] == '.')
						continue;
					email += s[idx];
				}
				while (s[idx] != '@')
					idx++;
				while (idx < len)
					email += s[idx++];
				umap[email]++;
			}
			return umap.size();
		}
};

