class Solution {
	public:
		int firstUniqChar(string s) {
			int arr[26] = {};
			int len = s.length();
			for (int i = 0; i < len; i++)
				arr[s[i] - 'a']++;
			for (int i = 0; i < len; i++)
				if (arr[s[i] - 'a'] == 1)
					return i;
			return -1;
		}
};

