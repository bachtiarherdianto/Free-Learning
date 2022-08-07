#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

/* Last Stone Weight
 * 
 * We have a collection of stones, each has a possitive integer weight
 * Each turn, we choose the two heaviest stones and smash them together.
 * Suppose the stones have weights x and y with x <= y.
 * The result of this smash is:
 * - If x == y, both stones are totally destroyed
 * - If x != y, the stone of weight x is totally destroyed and the stones
 *   of weight y has new weight as y-x
 * At the end, there is at most 1 stones left.
 * Return the weight of tisone stones (or 0 if there has no stones left)
 * 
 * Input : [2, 7, 4, 1, 8, 1]
 * Output: 1
 * - We combine 7 and 8 to get 1 ==> [2, 4, 1, 1, 1] then,
 * - We combine 2 and 4 to get 2 ==> [2, 1, 1, 1] then,
 * - We combine 2 and 1 to get 1 ==> [1, 1, 1] then,
 * - We combine 1 and 1 to get 0 ==> [1]                                 */
class Solution
{
public:
	int solved(std::vector<int>& stones)
	{
		std::multiset<int> s;
		for (int x : stones) {s.insert(x);}

		auto pop_max = [&]()
		{
			int x = *s.rbegin();
			s.erase(prev(s.end()));
			return x;
		};

		while((int) s.size() >= 2)
		{
			int y = pop_max();
			int x = pop_max();
			if (x != y) {s.insert(y-x);}
		}

		if (s.empty()) {return 0;}
		return pop_max();
	}
};

int main()
{
	Solution Competitive;

	std::vector<int> collection{2, 7, 4, 1, 8, 1};
	std::cout << Competitive.solved(collection) << std::endl;
	return 0;
}