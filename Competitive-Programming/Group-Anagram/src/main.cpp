/* Group Anagrams
 * 
 * Given an array of strings, group anagrams together
 * 
 * Input : ["eat", "tea", "tan", "ate", "nat", "bat"]
 * Output: [["bat"],
 *          ["ate", "eat", "tea"],
 *          ["nat", "tan"]]                           */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<std::string>> solved(std::vector<std::string>& strs)
    {
    	std::map<std::string, std::vector<std::string>> m;
    	for (std::string s : strs)
    	{
    		std::string s2 = s;
    		std::sort(s2.begin(), s2.end());
    		m[s2].push_back(s);
    	}

    	std::vector<std::vector<std::string>> v;
    	for (auto pp : m) {v.push_back(pp.second);}

    	return v;
    }

    void display(std::vector<std::vector<std::string>> nums)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < nums[i].size(); ++j)
			{std::cout << nums[i][j] << " ";}
			std::cout << std::endl;
		}
	}
};

int main()
{
	Solution Competitive;

	std::vector<std::string> arr{"eat", "tea", "tan", "ate", "nat", "bat"};
	
	std::vector<std::vector<std::string>> result = Competitive.solved(arr);
	Competitive.display(result);
	return 0;
}