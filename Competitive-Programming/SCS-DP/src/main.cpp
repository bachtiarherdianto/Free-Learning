#include <iostream>
#include <algorithm>
#include <cstring>

/* Shortest Common Supersequence
 * - Solve dynamic programming
 *
 * Given two string, str1 and str2, find the shortest string
 * that has both str1 and str2 as subsequence
 *
 * Input : str1 = "AGGTAB"
 *         str2 = "GXTXAYB"
 *         
 * Output: "AGXGTXAYB"                                      */
int AlgorithmSCS(char* X, char* Y, int m, int n);

int main()
{
  char str1[] = "AGGTAB";
  char str2[] = "GXTXAYB";
  std::cout << AlgorithmSCS(str1, 
                            str2, 
                            strlen(str1), 
                            strlen(str2)) 
            << std::endl;
  return 0;
}

int AlgorithmSCS(char* X, char* Y, int m, int n)
{
  int DynamicProgramming[m+1][n+1];
  for (int i = 0; i <= m; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      if (!i)
      {
        DynamicProgramming[i][j] = j;
      }
      else if (!j)
      {
        DynamicProgramming[i][j] = i;
      }
      else if (X[i-1] == Y[j-1])
      {
        DynamicProgramming[i][j] = 1 + DynamicProgramming[i-1][j-1];
      }
      else
      {
        DynamicProgramming[i][j] = 1 + std::min(DynamicProgramming[i-1][j],
                                                DynamicProgramming[i][j-1]);
      }
    }
  }
  return DynamicProgramming[m][n];
}