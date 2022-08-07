#include <iostream>
#include <algorithm>
#include <cstring>

/* Shortest Common Supersequence
 * - Solve using naive recursive
 *
 * Given two string, str1 and str2, find the shortest string
 * that has both str1 and str2 as subsequence
 *
 * Input : str1 = "AGGTAB"    // 6
 *         str2 = "GXTXAYB"   // 7
 *         
 * Output: 9                  // AGXGTXAYB                  */
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
  if (!m) return n;
  if (!n) return m;
  if (X[m-1] == Y[n-1])
  {
    return 1 + AlgorithmSCS(X, Y, m-1, n-1);
  }

  return 1 + std::min(AlgorithmSCS(X, Y, m-1, n), 
                      AlgorithmSCS(X, Y, m, n-1));
}