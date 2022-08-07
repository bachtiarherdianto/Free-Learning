#include <iostream>
#include <cstring>

/* Dice Throw Problem
 * - Solve using Dynamic Programming
 *
 * Given n dice, each with m faces, numbered from 1 to m, find the 
 * number of ways to get sum X, as sum(m, n, X), where X is the 
 * summation of values on each face when all the dice are thrown.
 *
 * Example:
 * sum(6, 3, 8) = sum(6, 2, 7) + sum(6, 2, 6) + sum(6, 2, 5) +
 *                sum(6, 2, 4) + sum(6, 2, 3) + sum(6, 2, 2)
 *
 * To evaluate sum(6, 2, 7), we can solve as following:
 * sum(6, 2, 7) = sum(6, 1, 6) + sum(6, 1, 5) + sum(6, 1, 4) +
 *                sum(6, 1, 3) + sum(6, 1, 2) + sum(6, 1, 1)
 *
 * To evaluate sum(6, 2, 6), we also can solve as following:
 * sum(6, 2, 6) = sum(6, 1, 5) + sum(6, 1, 4) + sum(6, 1, 3) +
 *                sum(6, 1, 2) + sum(6, 1, 1)
 * .................................................................
 * .................................................................
 * sum(6, 2, 2) = sum(6, 1, 1)                                    */
class Solution
{
public:
  int sum(int f, int d, int s)
  {
    int dp[d+1][s+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= d; ++i)
    {
      for (int j = i; j <= s; ++j)
      {
        dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
        if (j - f - 1 >= 0)
        {
          dp[i][j] -= dp[i-1][j-f-1];
        }
      }
    }

    return dp[d][s];
  }
}; 

int main()
{
  Solution Dynamic;

  // std::cout << Dynamic.sum(2, 2, 3) << std::endl;
  std::cout << Dynamic.sum(6, 3, 8) << std::endl;
  // std::cout << Dynamic.sum(4, 2, 5) << std::endl;
  // std::cout << Dynamic.sum(4, 3, 5) << std::endl; 
  return 0;
}