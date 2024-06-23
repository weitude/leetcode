class Solution {
	public:
		bool isPalindrome(string s) {
			string b = "";
			int n = s.size();
			int nb = 0;
			for (int i = 0; i < n; i++) {
				if (isalnum(s[i])) {
					b += tolower(s[i]);
					nb++;
				}
			}
			for (int i = 0; i < nb / 2; i++) {
				if (b[i] != b[nb - i - 1])
					return false;
			}
			return true;
		}
};

