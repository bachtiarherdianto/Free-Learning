#include <iostream>

/* Partition Problem
 * - Dividing an array into two subsets of equal sum
 * - Solve using Dynamic Programming
 *
 * Input  : arr[] = {1, 5, 11, 5}
 * Output : True
 * The array can be partitioned as 
 * {1, 5, 5} and {11}
 *
 * Input  : arr[] = {1, 5, 3}
 * Output : False
 * The array cannot be partitioned into equal sum sets */
class Solution
{
public:
  bool Main(int arr[], int n)
  {
    int sum = 0, i, j;
    for (i = 0; i < n; ++i)
    {
      sum += arr[i];
    }

    if (sum % 2 != 0)
    {
      return false;
    }

    bool part[sum/2 + 1][n + 1];
    for (i = 0; i <= sum/2; ++i)
    {
      part[i][0] = false;
    }

    for (i = 1; i <= sum/2; ++i)
    {
      for (j = 0; j <= n; ++j)
      {
        part[i][j] = part[i][j-1];
        if (i >= arr[j-1])
        {
          part[i][j] = part[i][j] || 
                       part[i-arr[j-1]][j-1];
        }
      }
    }
    return part[sum/2][n];
  }
};

int main()
{
  // int arr[] = {1, 5, 11, 5};
  int arr[] = {1, 5, 3};
  int len_of_arr = sizeof(arr)/sizeof(int);

  Solution Dynamic;

  (Dynamic.Main(arr, len_of_arr))? std::cout << "True\n"
                                 : std::cout << "False\n";
  return 0;
}