#include <iostream>
#include <vector>
#include <algorithm>

/* Maximal Square of Ones
 *
 * Given a 2D binary matrix filled with 0's and 1's.
 * Find the largest square containing only 1's and
 * return its value of area.
 *
 * Input:	1 0  1 0  0
 *          1 0 [1 1] 1
 *          1 1 [1 1] 1
 *          1 0  0 1  0
 *
 * Output:	4                                          */
class Solution
{
public:
	int solved(std::vector<std::vector<char>>& matrix)
	{
		int H = matrix.size();
		if (H == 0 || matrix[0].empty()) {return 0;}
		int W = matrix[0].size();
		std::vector<std::vector<int>> dp(H, std::vector<int>(W));
		int answer = 0;
		for (int row = 0; row < H; ++row)
		{
			for (int col = 0; col < W; ++col)
			{
				if (matrix[row][col] == '1')
				{
					dp[row][col] = 1;
					if (row > 0 && col > 0)	{dp[row][col] += std::min({dp[row-1][col], 
						                                               dp[row][col-1], 
						                                               dp[row-1][col-1]});}
					answer = std::max(answer, dp[row][col]);
				}
			}
		}
		return answer*answer;
	}
};


int main()
{
	Solution Competitive;
	std::vector<std::vector<char>> matrix{{'1', '0', '1', '0', '0'}, 
	                                      {'1', '0', '1', '1', '1'}, 
	                                      {'1', '1', '1', '1', '1'}, 
	                                      {'1', '0', '0', '1', '0'}};

	std::cout << Competitive.solved(matrix) << std::endl;;
	return 0;
}