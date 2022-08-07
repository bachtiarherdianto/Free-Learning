/* Maximum Subarray
 * 
 * Given an integer of arrays nums, find the contiguous subarray
 * (cotaining at least one number) which has the largest sum
 * 
 * Input : [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * Output: 6
 * [4, -1, 2, 1] has the largest sum = 6                         */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution
{
public:
	int solved(std::vector<int>& nums)
	{
		int result = INT_MIN;
		int a = 0;
		for (int x : nums)
		{
			a += x;
			result = std::max(result, a);
			a = std::max(a, 0);
		}
		return result;
	}	
};

int main()
{
	Solution Competitive;

	std::vector<int> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
	std::cout << Competitive.solved(input) << std::endl;
	return 0;
}