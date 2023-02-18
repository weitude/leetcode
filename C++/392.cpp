class Solution {
	public:
		bool isSubsequence(string s, string t) {
			int i = 0, j = 0;
			int lenS = s.length(), lenT = t.length();
			while(i < lenS && j < lenT)
			{
				if (s[i] == t[j])
				{
					i++;
					j++;
				}
				else
					j++;
			}
			if (i == lenS)
				return true;
			return false;
		}
};

