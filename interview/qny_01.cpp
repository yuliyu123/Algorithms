// pseudo code
// 二维矩阵只有0和1，求连续的1. 这里的连续只是左和右连续，斜线不连续。
int getMaxLen(std::vector<std::vector<int>> vec)
{
	if (vec.empty()) return 0;
	int counter = 0;
	int res = 0;
	int row = vec.size();
	int col = vec[0].size();

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			dfs(vec, i, j, counter, res);
		}
	}

	return res;
}

void dfs(std::vector<std::vector<int>> vec, int i, int j, int counter, int res)
{
	if (i < 0 || j < 0 || i > vec.size() - 1 || j > vec[0].size() - 1)
	{
		return;
	}

	if (vec[i][j] == 1)
	{
		++counter;
		res = res > counter ? res : counter;
	}
	else
	{
		counter = 0;
	}
	dfs(vec, m + 1, n, counter, res);
	// dfs(vec, m - 1, n, counter, res); 向上不考虑
	dfs(vec, m, n + 1, counter, res);
	dfs(vec, m, n - 1, counter, res);
}
