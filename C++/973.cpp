class Solution {
	public:
		vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
			priority_queue<pair<int, vector<int>>> pq;

			for (auto i: points) {
				int dis = i[0] * i[0] + i[1] * i[1];
				pq.push({dis, i});
				if (pq.size() > k)
					pq.pop();
			}

			vector<vector<int>> ans;

			while(!pq.empty()) {
				ans.push_back(pq.top().second);
				pq.pop();
			}

			return ans;
		}
};

