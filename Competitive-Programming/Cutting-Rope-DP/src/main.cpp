#include <iostream>

/* Maximum Product of Cutting Rope
 * - Solve using Dynamic Programming
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
  int solve(int n)
  {
    int result = 1;
    if (n == 2 || n == 3){return (n - 1);}

    while (n > 4)
    {
      n -= 3;
      result *= 3;
    }

    return(n * result);
  }
};

int main()
{
  Solution Dynamic;
  int n = 10;
  
  std::cout << Dynamic.solve(n) << std::endl;
  return 0;
}