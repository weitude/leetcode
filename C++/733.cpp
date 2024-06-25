class Solution {
	public:
		vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
			int m = image.size(), n = image[0].size();
			vector<vector<bool>> visited(m, vector<bool> (n, 0));
			queue<pair<int, int>> q;
			int dr[4] = {0, -1, 0, 1};
			int dc[4] = {1, 0, -1, 0};
			int o = image[sr][sc];
			q.push({sr, sc});
			visited[sr][sc] = true;

			while(!q.empty()) {
				auto &[r, c] = q.front();
				q.pop();
				if (image[r][c] == o)
					image[r][c] = color;
				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (nr < 0 || nr >= m || nc < 0 || nc >= n)
						continue;
					if (visited[nr][nc])
						continue;
					visited[nr][nc] = true;
					if (image[nr][nc] == o)
						q.push({nr, nc});
				}
			}
			return image;
		}
};

