#include <iostream>

/* Maximum Product of Cutting Rope
 * - Solve using Naive Recursive
 *
 * Given a rope of length n meters, cut the rope
 * in different parts of integer lengths, in a way
 * that maximizes product of lengths of all parts.
 * You have to make, at least, a cut and assume that
 * the length of rope is more than 2 meters
 *
 * Input: n = 4   ;     Output: 4
 * Maximum obtainabe product is 2*2
 * 
 * Input: n = 10  ;     Output: 36
 * Maximum obtainabe product is 3*3*4               */
class Solution
{
public:
  int max(int a, int b) {return (a > b)? a : b;}

  int max(int a, int b, int c) {return max(a, max(b, c));}

  int solve(int n)
  {
    int max_val = 0;
    if (n == 0 || n == 1)
    {
      return 0;
    }

    for (int i = 1; i < n; ++i)
    {
      max_val = max(max_val, i * (n -i), solve(n - i) * i);
    }

    return max_val;
  }
};

int main()
{
  Solution Recursive;
  int n = 10;

  std::cout << Recursive.solve(n) << std::endl;
  return 0;
}