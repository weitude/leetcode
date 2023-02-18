class Solution {
	public:
		int m, n;
		int cnt = 0, mx = 0;
		void countArea(vector<vector<int>> &grid, int row, int col)
		{
			if (row < 0 || row >= m || col < 0 || col >= n)
				return;
			if (grid[row][col] == 0)
				return;
			grid[row][col] = 0;
			cnt++;
			int offset[] = {0, 1, 0, -1, 0};
			for (int i = 0; i < 4; i++)
				countArea(grid, row + offset[i], col + offset[i + 1]);
		}

		int maxAreaOfIsland(vector<vector<int>>& grid)
		{
			m = grid.size();
			n = grid[0].size();
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (grid[i][j] == 1)
					{
						countArea(grid, i, j);
						mx = max(mx, cnt);
						cnt = 0;
					}
				}
			}
			return mx;
		}
};

