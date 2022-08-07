/* Search in Rotated Sorted Array
 * 
 * Suppose an array sorted in ascending order is rotared 
 * at some pivot unknown to you beforehand such as 
 * [0, 1, 2, 4, 5, 6, 7] might become [4, 5, 6, 7, 0, 1, 2]
 * You are given a target value to find out.
 * If it found then return its index
 * otherwise return -1
 * 
 * Input : nums = [4, 5, 6, 7, 0, 1, 2]
 *         target = 0
 * Output: 4                                               */
#include <iostream>
#include <vector>


class Solution
{
public:
	int solved(std::vector<int>& nums, int target)
	{
		int n = nums.size();
		if (n == 0) {return -1;}
		int low = 0;
		int high = n-1;
		int first = nums[0];
		while(low <= high)
		{
			int mid = low + (high - low)/2;
			int value = nums[mid];
			if (value == target) {return mid;}
			bool am_big = value >= first;
			bool target_big = target >= first;
			if (am_big == target_big)
			{
				if (value < target) {low = mid - 1;}
				else {high = mid - 1;}
			}
			else
			{
				if (am_big)	{low = mid + 1;}
				else {high = mid - 1;}
			}
		}
		return - 1;
	}	
};

int main()
{
	Solution Competitive;

	std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
	int target = 0;

	std::cout << Competitive.solved(nums, target) << std::endl;
	return 0;
}