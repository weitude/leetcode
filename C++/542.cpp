class Solution {
	public:
		vector<int> DIR = {0, 1, 0, -1, 0};

		vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
			int m = mat.size();
			int n = mat[0].size();
			queue<pair<int, int>> q;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (mat[i][j] == 0)
						q.push({i, j});
					else
						mat[i][j] = -1;
				}
			}

			while (!q.empty()) {
				auto [x, y] = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + DIR[i];
					int ny = y + DIR[i + 1];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n || mat[nx][ny] != -1)
						continue;
					mat[nx][ny] = mat[x][y] + 1;
					q.push({nx, ny});
				}
			}

			return mat;
		}
};

