class Solution
{
	public:
		int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
		{
			if (obstacleGrid[0][0])
				return 0;
			int row = obstacleGrid.size(), col = obstacleGrid[0].size();
			int m = 0, n = 1;
			while (m < row && !obstacleGrid[m][0])
				obstacleGrid[m++][0] = 1;
			while (m < row)
				obstacleGrid[m++][0] = 0;
			while (n < col && !obstacleGrid[0][n])
				obstacleGrid[0][n++] = 1;
			while (n < col)
				obstacleGrid[0][n++] = 0;

			for (int i = 1; i < row; i++)
			{
				for (int j = 1; j < col; j++)
				{
					if (!obstacleGrid[i][j])
						obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
					else
						obstacleGrid[i][j] = 0;
				}
			}
			return obstacleGrid[row - 1][col - 1];
		}
};

