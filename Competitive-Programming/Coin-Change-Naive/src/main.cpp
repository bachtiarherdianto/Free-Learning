#include <iostream>

/* Coin Change Problem
 * - Solve using Naive Recursive
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
    if (n == 0)
    {
      return 1;
    }

    if (n < 0)
    {
      return 0;
    }

    if (m <= 0 && n >= 1)
    {
      return 0;
    }

    return solved(S, m-1, n) + 
           solved(S, m, n-S[m-1]);
  }
};

int main()
{
  int N = 10;
  int arr[] = {2, 5, 3, 6};
  int size_of_arr = sizeof(arr)/sizeof(int);

  Solution Recursive;

  std::cout << Recursive.solved(arr, size_of_arr, N) << std::endl;
  return 0;
} 