/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (40.28%)
 * Total Accepted:    304.5K
 * Total Submissions: 755.9K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
class Solution_1
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    numIslandsDFS(grid, visited, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void numIslandsDFS(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y)
    {
        if (x < 0 || x >= grid.size())
            return;
        if (y < 0 || y >= grid[0].size())
            return;
        if (grid[x][y] != '1' || visited[x][y])
            return;
        visited[x][y] = true;
        numIslandsDFS(grid, visited, x - 1, y);
        numIslandsDFS(grid, visited, x + 1, y);
        numIslandsDFS(grid, visited, x, y - 1);
        numIslandsDFS(grid, visited, x, y + 1);
    }
};
class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    numIslandsDFS(grid, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void numIslandsDFS(vector<vector<char>> &grid,  int x, int y)
    {
        if (x < 0 || x >= grid.size())
            return;
        if (y < 0 || y >= grid[0].size())
            return;
        if (grid[x][y] != '1')
            return;
        grid[x][y] = '$';
        numIslandsDFS(grid,  x - 1, y);
        numIslandsDFS(grid,  x + 1, y);
        numIslandsDFS(grid, x, y - 1);
        numIslandsDFS(grid,  x, y + 1);
    }
};
