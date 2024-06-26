class Solution {
	public:
		int longestPalindrome(string s) {
			int freq[55];
			for (char &ch: s) {
				if ('A' <= ch && ch <= 'Z')
					freq[ch - 'A']++;
				else
					freq[ch - 'a' + 26]++;
			}
			bool odd = false;
			int ans = 0;
			for (int i = 0; i < 52; i++) {
				if (freq[i] % 2 == 0)
					ans += freq[i];
				else {
					ans += freq[i] - 1;
					odd = true;
				}
			}
			return odd ? ans + 1 : ans;
		}
};

