/* Break A Palindrome
 *
 * Given a palindromic string palindrome, replace exactly one character
 * by any lowercase English letter so that string becomes the lexicographically
 * smallest possible string that is not a palindrome
 * After doing so, return the final string, if there is no way to do so, return
 * the empty string
 *
 * Input: palindrome = "abccba"
 * Output: "aaccba"                                                            */
#include <iostream>
#include <string>


class Solution
{
public:
	std::string solved(std::string s)
	{
		int n = s.length();
		if (n == 1)	{return "";}
		for (int i = 0; i < n; ++i)
		{
			int j = n - 1 - i;
			if (i == j)	{continue;}
			if (s[i] != 'a')
			{
				s[i] = 'a';
				return s;
			}
		}
		s[n-1] = 'b';
		return s;
	}	
};

int main()
{
	Solution Competitive;

	std::string palindrome = "abccba";
	std::cout << Competitive.solved(palindrome) << std::endl;
	return 0;
}