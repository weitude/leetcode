class Solution {
public:
    int uniquePaths(int m, int n) {
		m--;
		n--;
		if (m < n)
			swap(m, n);
		long long sum = m + n + 1, up = 1, down = 1;
		for (int i = 1; i <= n; i++)
		{
			down *= i;
			up *= (sum - i);
			if (up > INT_MAX)
			{
				up /= down;
				down = 1;
			}		
		}
		return up / down;
    }
};

