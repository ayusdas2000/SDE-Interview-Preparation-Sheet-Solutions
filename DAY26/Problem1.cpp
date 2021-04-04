/**

Time Complexity - O(m*n)
Space Complexity - O(m*n)

Explanation:

We are starting from cell (Row-1,Col-1) and going to  (0,0) by,
either making a left move or upward move.

Base Cases: 
  - If we are at (0,0) all we have to consider is the value at that cell
  - If we move to some invalid position(i.e. outside the matrix) we
    ignore the movement by assigning some very large value (since we want 
    the minimum cost)

Main Tasks:
  - At every step we have the option to either go left or upward from that
    cell. So we consider both the cases, and each of the following cases
    represent a sub-problem of the original problem.
  - Thus we can save the result of all the overlapping sub-problems and incase
    any state is repeated we return the earlier computed result.
*/

class Solution 
{
  public:
      int recurse(const vector<vector<int>> &grid, vector<vector<int>>& memo, int x, int y) 
      {
        if (x == 0 and y == 0) 
          return grid[x][y];
        if (x < 0 or y < 0) 
          return INT_MAX;
        
        if (memo[x][y] > 0) 
          return memo[x][y];
        
        int ans = grid[x][y] + min(recurse(grid, memo, x - 1, y), recurse(grid, memo, x, y - 1));
        
        return memo[x][y] = ans;
      }


    int minPathSum(vector<vector<int>> &grid) 
    {
        int m = grid.size();
        if (m == 0) 
          return 0;
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return recurse(grid, memo, m - 1, n - 1);
    }
};
