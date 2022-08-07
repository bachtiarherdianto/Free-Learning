/* Happy Number
 * 
 * Is a number defined by the following process:
 * Starting with any positive integer, replace the number by 
 * the sum-squares of its digits and repeat the process until
 * the number equals 1 (where it will stay), or it loops endlessly
 * in a cycle which can include 1.
 * 
 * Input : 19
 * Output: True
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1 (True)                                     */
#include <iostream>


class Solution
{
public:
	int f(int n)
	{
		int sum = 0;
		while(n)
		{
			int digit = n % 10;
			n /= 10;
			sum += digit;
		}
		return sum;
	}

	bool solved(int n)
	{
		for (int rep = 0; rep < 20; ++rep)
		{
			n = f(n);
			if (n == 1) {return true;}
		}
		return false;
	}	
};

int main()
{
	Solution Competitive;

	(Competitive.solved(19))?  std::cout << "True\n"
	                        :  std::cout << "False\n";
	
	return 0;
}