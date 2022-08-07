#include <iostream>
#include <climits>

/* Matrix Chain Multiplication -Dynamic Programming
 *
 * Input : p[] = {40, 20, 30, 10, 30}
 * Output: 2600
 * There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30. 
 * Let the input 4 matrices as A, B, C and D, then the minimum number
 * of multiplicaions are obtained by putting parethesis in following way
 * (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
 *
 * Input : p[] = {10, 20, 30, 40, 30}
 * Output: 3000
 * There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
 * Let the input 4 matrices as A, B, C and D, then the minimum number
 * of multiplicaions are obtained by putting parethesis in following way
 * (AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30
 *
 * Input : p[] = {10, 20, 30}
 * Output: 6000
 * There are 3 matrices of dimensions 10x20, 20x30 and 20x30. 
 * Then the minimum number of multiplicaions are obtained as
 * (ABC) --> 10*20*30                                                   */
class Solution
{
public:
  int MatrixChainMultiplication(int p[], int n)
  {
    int dp[n][n];
    int i, j, k, Length, q;
    for (i = 1; i < n; ++i)
    {
      dp[i][i] = 0;
    }

    for (Length = 2; Length < n; ++Length)
    {
      for (i = 1; i < n - Length + 1; ++i)
      {
        j = i + Length - 1;
        dp[i][j] = INT_MAX;
        for (k = i; k <= j - 1; k++)
        {
          q = dp[i][k]   + 
              dp[k+1][j] + 
              p[i-1] * p[k] * p[j];
          if (q < dp[i][j])
          {
            dp[i][j] = q;
          }
        }
      }
    }
    return dp[1][n-1];
  }
};

int main()
{
  Solution Dynamic;

  int p[] = {40, 20, 30, 10, 30};
  // int p[] = {10, 20, 30, 40, 30};
  // int p[] = {10, 20, 30};
  int len_of_p = sizeof(p)/sizeof(int);

  std::cout << Dynamic.MatrixChainMultiplication(p, len_of_p) << std::endl;
  return 0;
}