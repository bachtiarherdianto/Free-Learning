#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

/* Binary Knapsack Problem to print all possible solution
 *
 * Input: Profits:  val = {60, 100, 120, 50}
 *        Weight :  wt  = {10, 20, 30, 40}
 *        Capacity: W   = 40
 *
 * Output:
 * 10: 60, 20: 100,
 * 10: 60, 30: 120,
 * Maximum Profit = 180
 *
 * Input: Profits:  val = {60, 100, 120, 50}
 *        Weight :  wt  = {10, 20, 30, 40}
 *        Capacity: W   = 60
 *
 * Output:
 * 10: 60, 20: 100, 30: 120,
 * 10: 60, 40: 50,
 * 20: 100, 40: 50,
 * Maximum Profit = 280                                   */
int MaxChoice(int a, int b);

int Solve(int W, std::vector<int> wt, std::vector<int> val, int n);

int main()
{
  std::vector<int> val{60, 100, 120, 50};
  int len_of_val = val.size();
  std::vector<int> wt{10, 20, 30, 40};
  int W = 60;
  int Knapsack = Solve(W, wt, val, len_of_val);

  std::cout << "Maximum Profit = ";
  std::cout << Knapsack << std::endl;
  return 0;
}

int MaxChoice(int a, int b)
{
  return (a > b)? a : b;
}

int Solve(int W, std::vector<int> wt, std::vector<int> val, int n)
{
  std::map<int, int> umap;
  std::set<std::vector<std::pair<int, int>>> set_sol;

  for (int i = 0; i < n; ++i)
  {
    umap.insert({wt[i], val[i]});
  }

  int result = INT_MIN;
  int remaining_weight;
  int sum;

  do
  {
    sum = 0;
    remaining_weight = W;
    std::vector<std::pair<int, int>> possible;

    for (int i = 0; i < n; ++i)
    {
      if (wt[i] <= remaining_weight)
      {
        remaining_weight -= wt[i];
        auto itr = umap.find(wt[i]);
        sum += (itr -> second);
        possible.push_back({itr -> first, itr -> second});
      }
    }

    sort(possible.begin(), possible.end());
    if (sum > result)
    {
      result = sum;
    }

    if (set_sol.find(possible) == set_sol.end())
    {
      for (auto sol : possible)
      {
        std::cout << sol.first << ": " << sol.second << ", ";
      }
      std::cout << std::endl;
      set_sol.insert(possible);
    }
  } while(next_permutation(wt.begin(), wt.end()));

  return result;
}