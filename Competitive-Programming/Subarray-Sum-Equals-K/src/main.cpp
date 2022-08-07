/* Subarray Sum Equals K
 *
 * Given an array of integers and an integer k. The taks is how to
 * find the total number of continuous subarray whose sum equals to k
 *
 * Input: nums = [1, 1, 1]	;	k = 2
 * Output: 2
 * [1, 1] => 1 + 1 = 2                                              */
#include <iostream>
#include <unordered_map>
#include <vector>


class Solution
{
public:
	int solved(std::vector<int>& nums, int k)
	{
		int n = nums.size();
		int answer = 0, pref = 0;
		std::unordered_map<int, int> countPref;
		countPref[pref]++;
		for (int i = 0; i < n; ++i)
		{
			pref += nums[i];
			int need = pref - k;
			answer += countPref[need];
			countPref[pref]++;
		}
		return answer;
	}	
};

int main()
{
	Solution Competitive;

	std::vector<int> nums {1, 1, 1};
	int k = 2;
	std::cout << Competitive.solved(nums, k) << std::endl;
	return 0;
}