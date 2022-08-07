#include <iostream>
#include <climits>

/* Egg Dropping Problem
 * - Solve using Naive Recursive
 *
 * The problem involving n = 2 eggs and a building with k = 8 floors.
 * Suppose that we wish to know which stories in a 8-floors building
 * are safe to drop eggs from, and which will cause the eggs to break
 * when landing. We make some assumptions such as:
 * 
 * -- An egg that survives a fall can be used again.
 * -- A broke egg have to be discarded.
 * -- The effect of a fall is the same for all eggs
 * -- If an egg breaks when dropped, thus it would like to
 *    break if it dropped from a higher floor
 * -- If an egg sursives from a particular floor, it would like to
 *    survive when falling from shorter floor
 * -- It is not ruled out that the first-floor windows break eggs, nor
 *    it is ruled out that the 36th-floor do not cause an egg to break
 *
 * - If only one egg is available and we wish to be sure of obtaining 
 *   the right result, the experiment can be carried out in only one way.
 * - Drop the egg from first-floor window, then if it surive, drop it again
 *   from second-floor window, then continue until it breaks
 * - The problem is not actually to find the critical floor, but to decide
 *   which floor be decided to drop the eggs, so that 
 *   the total number of trials are minimized                              */
class Solution
{
 public:
 int max(int a, int b){return (a > b)? a : b;}

 int solve(int n, int k)
 {
  int min = INT_MAX, x, solution;
  if (k == 1 || k == 0)
  {
    return k;
  }

  if (n == 1)
  {
    return k;
  }

  for (x = 1; x <= k; ++x)
  {
    solution = max(solve(n-1, x-1), solve(n, k-x));
    if (solution < min)
    {
      min = solution;
    }
  }

  return min + 1;
 }
};   

int main()
{
  int n = 2, k = 8;

  Solution Recursive;

  std::cout << "Minimum number of trials in worst case with " << n
            << " eggs and a building with " << k << "-floors is "
            << Recursive.solve(n, k) << std::endl;
  return 0;
}