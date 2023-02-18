class Solution {
	public:
		int m, n;
		void erase(vector<vector<char>> &grid, int row, int col)
		{
			if (row < 0 || row >= m || col < 0 || col >= n)
				return;
			if (grid[row][col] == '0')
				return;

			grid[row][col] = '0';
			int offset[] = {0, 1, 0, -1, 0};
			for (int i = 0; i < 4; i++)
				erase(grid, row + offset[i], col + offset[i + 1]);
		}

		int numIslands(vector<vector<char>>& grid)
		{
			m = grid.size(), n = grid[0].size();
			int cnt = 0;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (grid[i][j] == '1')
					{
						cnt++;
						erase(grid, i, j);
					}
				}
			}
			return cnt;
		}
};

