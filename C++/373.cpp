using pii = pair<int, int>;
using pr = pair<int, pii>;

class Solution {
	public:
		vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
			priority_queue<pr, vector<pr>, greater<pr>> pq;
			set<pii> st;
			vector<vector<int>> ans;

			pq.push({nums1[0] + nums2[0], {0, 0}});
			st.insert({0, 0});

			bool flag = true;
			for (int cnt = 0; cnt < k && flag; cnt++)
			{
				pr temp = pq.top();
				pq.pop();

				int i = temp.second.first;
				int j = temp.second.second;
				vector<int> v = {nums1[i], nums2[j]};
				ans.push_back(v);

				flag = false;
				if (i + 1 < nums1.size())
				{
					flag = true;
					int sum = nums1[i + 1] + nums2[j];
					pii idx = {i + 1, j};
					if (!st.count(idx))
					{
						st.insert(idx);
						pq.push({sum, idx});
					}
				}
				if (j + 1 < nums2.size())
				{
					flag = true;
					int sum = nums1[i] + nums2[j + 1];
					pii idx = {i, j + 1};
					if (!st.count(idx))
					{
						st.insert(idx);
						pq.push({sum, idx});
					}
				}
			}
			return ans;
		}
};

