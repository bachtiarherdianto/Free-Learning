/* Counting Elements
 * 
 * Given an integer array arr, count element x such that x+1 is also in arr
 * If there are duplicates in arr, count the separately
 * 
 * Input: arr = [1, 2, 3]	;	x = 2
 * Output: 2
 * 1 and 2 are counted cause 2 and 3 are in arr                              */
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9 + 5;

class Solution
{
public:
	int solved(std::vector<int>& arr, int K)
	{
		int n = arr.size();
		std::sort(arr.begin(), arr.end());
		int prv = -INF; 
		int prv_cnt = 0, answer;
		int before_me_value = -INF;
		for (int i = 0; i < n; ++i)
		{
			if (i == n-1 || arr[i] != arr[i+1])
			{
				if ((i != n-1 && arr[i+1] <= arr[i]+K) || before_me_value >= arr[i]-K)
				{
					answer += prv_cnt;
				}
			}
			if (arr[i] == prv)
			{
				prv_cnt++;
			}
			else
			{
				before_me_value = prv;
				prv = arr[i];
				prv_cnt = 1;
			}
		}
		return answer;
	}	
};

int main()
{
	Solution Competitive;

	std::vector<int> arr{1, 2, 3};
	int x = 2;
	std::cout << Competitive.solved(arr, x) << std::endl;
	return 0;
}