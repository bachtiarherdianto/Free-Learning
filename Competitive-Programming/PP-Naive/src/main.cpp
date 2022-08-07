#include <iostream>

/* Partition Problem
 * - Dividing an array into two subsets of equal sum
 * - Solve using Naive Recursive
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
  bool Helper(int arr[], int n, int sum)
  {
    if (sum == 0)
    {
      return true;
    }

    if (n == 0 && sum != 0)
    {
      return false;
    }

    if (arr[n-1] > sum)
    {
      return Helper(arr, n-1, sum);
    }

    return Helper(arr, n-1, sum) || Helper(arr, n-1, sum-arr[n-1]);
  }

  bool Main(int arr[], int n)
  {
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
      sum += arr[i];
    }

    if (sum % 2 != 0)
    {
      return false;
    }

    return Helper(arr, n, sum/2);
  }
};

int main()
{
  int arr[] = {1, 5, 11, 5};
  // int arr[] = {1, 5, 3};
  int len_of_arr = sizeof(arr)/sizeof(int);

  Solution Recursive;

  (Recursive.Main(arr, len_of_arr))? std::cout << "True\n"
                                   : std::cout << "False\n";
  return 0;
}