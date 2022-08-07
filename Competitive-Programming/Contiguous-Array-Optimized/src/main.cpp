/* Contiguous Array
 * 
 * Given a binary array, find the maximum lenght of a contiguous subarray
 * with equal number of 0 and 1
 * 
 * Input : [0, 1]
 * Output: 2
 * - [0, 1] is the longest contiguous array
 * 
 * Input : [0, 1, 0]
 * Output: 2
 * [0, 1] is the longest contiguous array                                */
#include <iostream>
#include <vector>
#include <unordered_map>


class Solution
{
public:
	int solved(std::vector<int>& nums)
	{
		std::unordered_map<int, int> first_oc;
		first_oc[0] = 0;
		int answer = 0;
		int pref = 0;
		for (int i = 0; i < (int) nums.size(); ++i)
		{
			pref += (nums[i] == 0?  -1  :  1);
			auto it = first_oc.find(pref);
			if (it != first_oc.end())
			{answer = std::max(answer, i + 1 - first_oc[pref]);}
			else
			{first_oc[pref] = i + 1;}
		}
		return answer;
	}	
};

int main()
{
	Solution Competitive;

	std::vector<int> input{0, 1};
	// std::vector<int> input{0, 1, 0};
	std::cout << Competitive.solved(input) << std::endl;
	return 0;
}