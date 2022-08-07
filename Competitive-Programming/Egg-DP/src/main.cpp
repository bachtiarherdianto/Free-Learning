#include <iostream>
#include <climits>

/* Egg Dropping Problem
 * - Solve using Dynamic Programming
 *
 * The problem involving n = 2 eggs and a building with k = 36 floors.
 * Suppose that we wish to know which stories in a 36-floors building
 * are safe to drop eggs from, and which will cause the eggs to break
 * when landing. We make some assumptions such as:
 * 
 * -- An egg that survives a fall can be used again.
 * -- A broke egg have to be discarded.
 * -- The effect of a fall is the same for all eggs
 * -- If an egg breaks when dropped, thus it would like to
 *    break if it dropped from a higher floor
 * -- If an egg sursives from a particular floor, it would like to
 *    survive when falling from shorter floor
 * -- It is not ruled out that the first-floor windows break eggs, nor
 *    it is ruled out that the 36th-floor do not cause an egg to break
 *
 * - If only one egg is available and we wish to be sure of obtaining 
 *   the right result, the experiment can be carried out in only one way.
 * - Drop the egg from first-floor window, then if it surive, drop it again
 *   from second-floor window, then continue until it breaks
 * - The problem is not actually to find the critical floor, but to decide
 *   which floor be decided to drop the eggs, so that 
 *   the total number of trials are minimized                              */
class Solution
{
 public:
 int max(int a, int b){return (a > b)? a : b;}

 int solve(int n, int k)
 {
 	int dp[n+1][k+1];
 	int solution, i, j, x;
 	for (i = 1; i <= n; ++i)
 	{
 		dp[i][1] = 1;
 		dp[i][0] = 0;
 	}

 	for (j = 1; j <= k; ++j)
 	{
 		dp[1][j] = j;
 	}

 	for (i =2; i <= n; ++i)
 	{
 		for (j = 2; j <= k; ++j)
 		{
 			dp[i][j] = INT_MAX;
 			for (x = 1; x <= j; ++x)
 			{
 				solution = 1 + max(dp[i-1][x-1], 
 					               dp[i][j-x]);
 				if (solution < dp[i][j])
 				{
 					dp[i][j] = solution;
 				}
 			}
 		}
 	}

 	return dp[n][k];
 }
};   

int main()
{
  int n = 2, k = 8;

  Solution Dynamic;

  std::cout << "Minimum number of trials in worst case with " << n
            << " eggs and a building with " << k << "-floors is "
            << Dynamic.solve(n, k) << std::endl;
  return 0;
}