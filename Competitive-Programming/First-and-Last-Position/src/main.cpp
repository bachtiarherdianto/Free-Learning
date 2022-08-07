/* Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in ascending order
 * find the starting and ending position of a given target value
 * Note: the complexity have to O(log n)
 * 
 * Input: nums = [5, 7, 7, 8, 8, 10]	;	target = 8
 * Output: [3, 4]                                               */
#include <iostream>
#include <vector>


class Solution
{
	int helper(std::vector<int>& a, int x)
	{
		int n = a.size();
		int first_pos = n, low = 0, high = n - 1;
		while(low <= high)
		{
			int mid = low + (high - low) / 2;
			if (a[mid] >= x)
			{
				first_pos = mid;
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		return first_pos;
	}
public:
	std::vector<int> solved(std::vector<int> & a, int x)
	{
		int first = helper(a, x);
		int last = helper(a, x+1) - 1;
		if (first <= last)
		{
			return {first, last};
		}
		return {-1, 1};
	}

	void display(std::vector<int> v)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}	
};

int main()
{
	Solution Competitive;

	std::vector<int> nums {5, 7, 7, 8, 8, 10};
	int target = 8;
	
	std::vector<int> output = Competitive.solved(nums, target);
	Competitive.display(output);
	return 0;
}