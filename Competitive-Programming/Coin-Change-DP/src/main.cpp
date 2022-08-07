#include <iostream>
#include <cstring>

/* Coin Change Problem
 * - Solve using Dynamic Programming
 *
 * Given a value N, if we want to make change for N cents, and
 * we have infinite supply of eachof S = {S1, S2, ..., Sm} valued coints,
 * how many waus can we make the change?
 * The order of coints does not matter
 *
 * Input  : N = 10 and S = {2, 5, 3, 6}
 * Output : 5
 * There are five solution:
 * - {2, 2, 2, 2, 2} = 10
 * - {2, 2, 3, 3}    = 10
 * - {2, 2, 6}       = 10
 * - {2, 3, 5}       = 10
 * - {5, 5}          = 10                                                */
class Solution
{
public:
  int solved(int S[], int m, int n)
  {
    int i, j, x, y;
    int dp[n+1][m];
    for (i = 0; i < m; ++i)
    {
      dp[0][i] = 1;
    }

    for (i = 1; i < n+1; ++i)
    {
      for (j = 0; j < m; ++j)
      {
        x = (i - S[j] >= 0)? dp[i - S[j]][j]
                           : 0;
        y = (j >= 1)? dp[i][j-1]
                    : 0;
        dp[i][j] = x + y;
      }
    }
    return dp[n][m-1];
  }

  int solvedOptimized(int S[], int m, int n)
  {
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < m; ++i)
    {
      for (int j = S[i]; j <= n; ++j)
      {
        dp[j] += dp[j-S[i]];
      }
    }

    return dp[n];
  }
};

int main()
{
  int N = 10;
  int arr[] = {2, 5, 3, 6};
  int size_of_arr = sizeof(arr)/sizeof(int);

  Solution Dynamic;

  // std::cout << Dynamic.solved(arr, size_of_arr, N)          << "\n";
  std::cout << Dynamic.solvedOptimized(arr, size_of_arr, N) << "\n";
  return 0;
} 