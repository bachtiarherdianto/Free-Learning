/* Single Number
 * - linear runtime complexity
 * 
 * Given a non-empty array of integers, every element appear
 * twice except for one. Find that single one
 * 
 * Input: [6, 6, 8, 8, 2]
 * Output: 2                                                   */
#include <iostream>
#include <vector>

class Solution
{
public:
	int solved(std::vector<int> nums)
	{
		int x = 0;
		for (int a : nums)
		{
			x ^= a;
		}
		return x;
	}
};

int main()
{
	Solution SingeNumber;

	std::cout << SingeNumber.solved(std::vector<int> {6, 6, 8, 8, 2}); 
	return 0;
}