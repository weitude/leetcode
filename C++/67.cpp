class Solution {
	public:
		string addBinary(string a, string b) {
			string ans = "";
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			int na = a.size();
			int nb = b.size();
			if (na > nb) {
				swap(a, b);
				swap(na, nb);
			}
			int carry = 0;
			for (int i = 0; i < na; i++) {
				int sum = a[i] - '0' + b[i] - '0' + carry;
				carry = sum / 2;
				ans += sum % 2 + '0';
			}
			for (int i = na; i < nb; i++) {
				int sum = b[i] - '0' + carry;
				carry = sum / 2;
				ans += sum % 2 + '0';
			}
			if (carry)
				ans += '1';
			reverse(ans.begin(), ans.end());
			return ans;
		}
};

