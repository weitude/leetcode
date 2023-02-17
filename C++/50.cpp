class Solution {
	public:
		double fpow(double base, long long exp)
		{
			if (!exp)
				return 1;
			double ans = fpow(base * base, exp / 2);
			return (exp & 1 ? ans * base : ans);
		}

		double myPow(double x, int n) {
			if (n < 0)
				return 1.0 / fpow(x, -(long long)n);
			return fpow(x, n);
		}
};

