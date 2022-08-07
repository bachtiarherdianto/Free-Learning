#include <iostream>
#include <cstring>

/* Dice Throw Problem
 * - Solve using Naive Recursive
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
  int sum(int m, int n, int x)
  {
    int dummy[n+1][x+1];
    memset(dummy, 0, sizeof(dummy));
    for (int index = 0; index <= m && index <= x ; ++index)
    {
      dummy[1][index] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
      for (int j = 1; j <= x; ++j)
      {
        for (int k = 1; k <= m && k < j; ++k)
        {
          dummy[i][j] += dummy[i-1][j-k];
        }
      }
    }

    return dummy[n][x];
  }
}; 


int main()
{
  Solution Recursive;

  // std::cout << Recursive.sum(2, 2, 3) << std::endl;
  std::cout << Recursive.sum(6, 3, 8) << std::endl;
  // std::cout << Recursive.sum(4, 2, 5) << std::endl;
  // std::cout << Recursive.sum(4, 3, 5) << std::endl; 
  return 0;
}