/* Minimum Path Sum
 * 
 * Given a mxn matrix filled with non-negative numbers, find a path
 * from top left to bottom right which minimizes the sum of all
 * numbers along its path. Note that you can only move either down
 * or right at any point in time
 * 
 * Input:	[[1, 3, 1],
 *           [1, 5, 1],
 *           [4, 2, 1]]
 * Output: 7
 * because the path 1->3->1->1->1 minimize the sum                */
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>


class Solution
{
public:
	int solved(std::vector<std::vector<int>>& grid)
	{
		int H = grid.size();
		int W = grid[0].size();
		std::vector<std::vector<int>> dp(H, std::vector<int>(W));
		for (int row = 0; row < H; ++row)
		{
			for (int col = 0; col < W; ++col)
			{
				if (row == 0 && col == 0)
				{
					dp[row][col] = grid[row][col];
				}
				else
				{
					dp[row][col] = grid[row][col] + 
					               std::min(
					               	(row == 0? INT_MAX 
					               		     : dp[row-1][col]), 
					               	(col == 0? INT_MAX 
					               		     : dp[row][col-1])
					               	);
				}
			}
		}
		return dp[H-1][W-1];
	}	
};

int main()
{
	Solution Competitive;

	std::vector<std::vector<int>> input {{1, 3, 1},
                                         {1, 5, 1},
                                         {4, 2, 1}};
    std::cout << Competitive.solved(input) << std::endl;
	return 0;
}