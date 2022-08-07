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
 * - [0, 1] is the longest contiguous array                              */
#include <iostream>
#include <vector>
#include <unordered_map>


class Solution
{
public:
	int solved(std::vector<int>& nums)
	{
		int n = nums.size(), answer= 0;
		for (int i = 0; i < n; ++i)
		{if (nums[i] == 0) {nums[i] = -1;}}

		std::vector<int> pref;
		pref.push_back(0);
		for (int x : nums)
		{pref.push_back(pref.back() + x);}

		std::unordered_map<int, int> first_oc;
		for (int i = 0; i < (int) pref.size(); ++i)
		{
			int x = pref[i];
			auto itr = first_oc.find(x);
			if (itr != first_oc.end()) 
				{answer = std::max(answer, i - first_oc[x]);}
			else
				{first_oc[x] = i;}
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