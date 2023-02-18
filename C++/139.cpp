class Solution {
	public:
		bool wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> dict(wordDict.begin(), wordDict.end());
			int len = s.length();
			vector<bool> dp(len + 1, false);
			dp[0] = true;

			for (int i = 1; i <= len; i++)
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (dp[j])
					{
						string sub = s.substr(j, i - j);
						if (dict.count(sub))
						{
							dp[i] = true;
							break;
						}
					}
				}
			}
			return dp[len];
		}
};

