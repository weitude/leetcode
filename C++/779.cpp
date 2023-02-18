class Solution {
	public:
		int base[31] = {};

		int solve(int n , int k)
		{
			if (n == 1)
				return 0;
			if (k > base[n - 2])
				return solve(n, k - base[n - 2]) ^ 1;
			return solve(n - 1, k);
		}

		int kthGrammar(int n, int k) {
			base[0] = 1;
			for (int i = 1; i < 31; i++)
				base[i] = base[i - 1] * 2;
			return solve(n, k);
		}
};

