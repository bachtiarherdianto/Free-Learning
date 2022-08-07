#include <iostream>
#include <algorithm>
#include <cstring>

/* Shortest Common Supersequence
 * - Solve optimized dynamic programming
 *
 * Given two string, str1 and str2, find the shortest string
 * that has both str1 and str2 as subsequence
 *
 * Input : str1 = "AGGTAB"
 *         str2 = "GXTXAYB"
 *         
 * Output: "AGXGTXAYB"                                      */
int MaxChoice(int a, int b);

int LengthCommonSupersequence(char* X, char* Y, int m, int n);

int AlgorithmSCS(char *X, char *Y);

int main()
{
  char str1[] = "AGGTAB";
  char str2[] = "GXTXAYB";
  std::cout << AlgorithmSCS(str1, str2) << std::endl;
  return 0;
}

int MaxChoice(int a, int b)
{
  return (a > b)? a : b;
}

int LengthCommonSupersequence(char* X, char* Y, int m, int n)
{
  int DynamicProgramming[m+1][n+1];
  int i, j;
  for (int i = 0; i <= m; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      if (i == 0 || j == 0)
      {
        DynamicProgramming[i][j] = 0;
      }
      else if (X[i-1] == Y[j-1])
      {
        DynamicProgramming[i][j] = DynamicProgramming[i-1][j-1] + 1;
      }
      else
      {
        DynamicProgramming[i][j] = MaxChoice(DynamicProgramming[i-1][j],
                                             DynamicProgramming[i][j-1]);
      }
    }
  }
  return DynamicProgramming[m][n];
}

int AlgorithmSCS(char *X, char *Y)
{
  int Length = LengthCommonSupersequence(X, Y, 
                                         strlen(X), 
                                         strlen(Y));
  return (strlen(X) + strlen(Y) - Length);
}