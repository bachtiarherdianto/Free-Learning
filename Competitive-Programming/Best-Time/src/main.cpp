/* Best Time to Buy and Sell Stock
 * 
 * Say you have an array for which the i-th element is the price
 * of a given stock on day i, the task is how to find maximum profit
 * Note that you may complete as many transactions as you like, such as
 * buy one and sell one share of the stock multiple times
 * 
 * Input : [7, 1, 5, 3, 6, 4]
 * Output: 7
 * - buy on day 2 (price = 1) then sell on day 3 (price = 5): profit = 5 - 1 = 4, thus
 * - buy on day 4 (price = 3 and sell on day 5 (price = 6): profit = 6 - 3 = 3, thus
 *   the total profit is 4 + 3 = 7                                                     */
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9 + 5;

class Solution
{
public:
	int solved(std::vector<int>& prices)
	{
		int best_without_stock = 0, best_with_stock = -INF;
		for (int x : prices)
		{
			best_with_stock = std::max(best_with_stock, best_without_stock - x);
			best_without_stock = std::max(best_without_stock, best_with_stock + x);
		}
		return best_without_stock;
	}
};

int main()
{
	Solution Competitive;

	std::vector<int> value{7, 1, 5, 3, 6, 4};
	std::cout << Competitive.solved(value) << std::endl;;
	return 0;
}   