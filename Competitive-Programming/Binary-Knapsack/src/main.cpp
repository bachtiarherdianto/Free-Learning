#include <iostream>
#include <climits>

/* Binary Knapsack Queries
 *
 * Given an int array W[], consisting of weights of the items and some
 * queries consisting of capacity C of knapsack, for each query find
 * maximum weight that we can put in the knapsack.
 * Value of C does not exceed a certain int C_MAX
 *
 * Input: W[] = {3, 8, 9}
 *        q[] = {11, 10, 4}
 * 
 * Output:
 * 11
 * 9
 * 3
 *
 * If C = 11: select 3 + 8 = 11
 * If C = 10: select 9
 * If C = 4 : select 3
 *
 * Input: W[] = {1, 5, 10}
 *        q[] = {6, 14}
 *
 * Output:
 * 6
 * 11
 *
 * If C = 6 : select 1 + 5 = 6
 * If C = 14: select 1 + 10 = 11                                     */
#define C_MAX 30
#define MAX_ARR_LEN 10

int dp[MAX_ARR_LEN][C_MAX + 1];

bool v[MAX_ARR_LEN][C_MAX + 1];

int FindMax(int i, int r, int w[], int n);

void PreCompute(int w[], int n);

int AnsQuery(int w);

int main()
{
  // int W[] = {3, 8, 9}
  int W[] = {1, 5, 10};
  int len_of_w = sizeof(W)/sizeof(int);

  // Performing required pre-computation
  PreCompute(W, len_of_w);

  // int q[] = {11, 10, 4}
  int q[] = {6, 14};
  int len_of_q = sizeof(q)/sizeof(int);

  // Performing the algorithm
  for (int i = 0; i < len_of_q; ++i)
  {
    std::cout << AnsQuery(q[i]) << std::endl;
  }
  return 0;
}

int FindMax(int i, int r, int w[], int n)
{
  if (r < 0)
  {
    return INT_MIN;
  }

  if (i == n)
  {
    return 0;
  }

  if (v[i][r])
  {
    return dp[i][r];
  }

  v[i][r]  = 1;
  dp[i][r] = std::max(w[i] + FindMax(i + 1, r - w[i], w, n), 
                      FindMax(i + 1, r, w, n));
  return dp[i][r];
}

void PreCompute(int w[], int n)
{
  for (int i = C_MAX; i >= 0; --i)
  {
    FindMax(0, i, w, n);
  }
}

int AnsQuery(int w)
{
  return dp[0][w];
}