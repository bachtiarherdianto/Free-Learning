#include <iostream>
#include <algorithm>

/* Knapsack with large weight
 * - Solve using Naive Recursive
 *
 * Given a knapsack with capacity C and two arrays, weight w[] 
 * and value val[], for N distinct items, the problem is to find
 * the maximum value you can put into the knapsack.
 * Items cannot be broken and an item with weight x takes 
 * x capacity of knapsack where x is have to smaller than C.
 *
 * Input: w[]   = {3000, 4000, 5000}
 *        val[] = {30, 50, 60}
 *        C     = 8000
 *
 * Output: 90
 *
 * Take objects '1' and '3', thus the total value is (30 + 60 =) 90
 * Total weight is (3000 + 5000 =) 8000 which fits to given capacity */
#define V_SUM_MAX 1000
#define N_MAX 100
#define W_MAX 10000000


int dp[V_SUM_MAX + 1][N_MAX];

bool v[V_SUM_MAX + 1][N_MAX];

class Solution
{
public:
	int helper(int r, int i, int* w, int* val, int n)
	{
		if (r <= 0)  {return 0;}
		if (i == n)	 {return W_MAX;}
		if (v[r][i]) {return dp[r][i];}

		v[r][i] = 1;
		dp[r][i] = std::min(helper(r, i+1, w, val, n),
			                w[i] + helper(r - val[i], i+1, w, val, n));
		return dp[r][i];
	}

	int solved(int* w, int* val, int n, int c)
	{
		for (int i = V_SUM_MAX; i >= 0; --i)
		{
			if (helper(i, 0, w, val, n) <= c) {return i;}
		}
		return 0;
	}	
};

int main()
{
	Solution Recursive;

	int w[] = {3000, 4000, 5000};
	int val[] = {30, 50, 60};
	int C = 8000;
	int len_of_w = sizeof(w)/sizeof(int);

	std::cout << Recursive.solved(w, val, len_of_w, C) << std::endl;
	return 0;
}