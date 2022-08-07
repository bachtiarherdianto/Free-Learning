/* Move Zeroes
 * 
 * Given an array nums, write a function to move allk 0's to the end
 * of it while maintaining the relative order of the non-zero elements
 * 
 * Input : [0, 1, 0, 3, 12]
 * Output: [1, 3, 12, 0, 0]
 * Note: have to maintain the order of an array                        */
#include <iostream>
#include <vector>

class Solution
{
public:
	void solved(std::vector<int>& nums)
	{
		int n = nums.size();
		int next = 0;
		for (int x : nums)
		{
			if (x != 0)
			{
				nums[next] = x;
				next++;
			}
		}

		for (int i = next; i < n; ++i)
		{
			nums[i] = 0;
		}
	}

	void display(std::vector<int> nums)
	{
		std::cout << "[ ";
		for (int i : nums){std::cout << i << " ";}
		std::cout << "]" << std::endl;
	}	
};

int main()
{
	Solution Competitive;

	std::vector<int> input{0, 1, 0, 3, 12};
	Competitive.display(input);

	Competitive.solved(input);
	Competitive.display(input);
	return 0;
}   