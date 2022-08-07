/* Backspace String Compare
 * 
 * Given two strings S and T, return if they are equal when both are
 * typed into empty text editors. # means a backspace character.
 * 
 * Input: S = "ab#c"	;	T = "ad#c"
 * Output: True
 * Both S and T become "ac"                                         */
#include <iostream>
#include <string>

class Solution
{
	void remove(std::string& s, int& len)
	{
		for (int i = 0; i < (int) s.length(); ++i)
		{
			if (s[i] == '#') 
			{
				if (len > 0) {len--;}
			}
			else
			{
				s[len] = s[i];
				len++;
			}
		}
	}
	
public:
	bool solved(std::string S, std::string T)
	{
		int len_s = 0, len_t = 0;
		remove(S, len_s);
		remove(T, len_t);
		if (len_s != len_t)	{return false;}
		for (int i = 0; i < len_s; ++i)
		{
			if (S[i] != T[i]) {return false;}
		}
		return true;
	}
};

int main()
{
	Solution Competitive;

	std::string S = "ab#c";
	std::string T = "ad#c";
	(Competitive.solved(S, T))? std::cout << "True\n" 
	                          : std::cout << "False\n";
	return 0;
}