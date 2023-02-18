class Solution {
	public:
		bool check(vector<int> &weights, int cap, int days)
		{
			int sum = 0, need = 0, idx = 0;
			while (idx < weights.size())
			{
				if (sum + weights[idx] > cap)
				{
					need++;
					if (need > days)
						return false;
					sum = 0;
				}
				else
					sum += weights[idx++];
			}
			return need < days;
		}

		int shipWithinDays(vector<int>& weights, int days)
		{
			int left = 0, right = 0;
			for (int w : weights)
			{
				left = max(left, w);
				right += w;
			}
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (check(weights, mid, days))
					right = mid;
				else
					left = mid + 1;
			}
			return left;
		}
};

