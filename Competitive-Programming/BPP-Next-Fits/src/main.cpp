#include <iostream>

/* Bin Packing Problem
 * - Minimize number of used Bins
 * - Solve by Next Fits Algorithm
 *
 * Given n items of different weights and bins that each of capacity Capacity,
 * assign each item to a bin such that number of total used bins is minimized.
 * It may be assumed that all items have weights smaller than capacity of bin.
 *
 * Input: weight[] = {4, 8, 1, 4, 2, 1}
 *        Capacity = 10
 *
 * Output: We need minimum 2 bins to accomodate all items
 *
 * Input: weight[] = {9, 8, 2, 2, 5, 4}
 *        Capacity = 10
 *
 * Output: We need minimum 4 bins to accomodate all items
 *
 * Input: weight[] = {2, 5, 4, 7, 1, 3, 8}
 *        Capacity = 10
 *
 * Output: We need minimum 3 bins to accomodate all items                    */
int BinPacking(int weight[], int n, int c);

int main()
{
  // int weight[] = {4, 8, 1, 4, 2, 1};
  // int weight[] = {9, 8, 2, 2, 5, 4};
  int weight[] = {2, 5, 4, 7, 1, 3, 8};
  int Capacity = 10;
  int len_of_weight = sizeof(weight)/sizeof(int);

  std::cout << "We need minimum " 
            << BinPacking(weight, len_of_weight, Capacity) 
            << " to accomodate all items" << std::endl;
  return 0;          
}


int BinPacking(int weight[], int n, int c)
{
  int result = 0, bin_rem = c;
  for (int i = 0; i < n; ++i)
  {
    if (weight[i] > bin_rem)
    {
      bin_rem = c - weight[i];
      result++;
    }
    else
    {
      bin_rem -= weight[i];
    }
  }
  return result;
} 