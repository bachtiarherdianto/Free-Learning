#include <iostream>
#include <map>
#include <set>


/* Chech wheter string can be rearranged so that 
 * every odd length substring is Palindrome 
 * 
 * Given a string S. The task is to check whether it is possible to rearrange 
 * the string such that every substring of odd length is palindrome
 * 
 * Example:
 * Input  : 'oiooi'
 * Output :  Yes     // the string can be rearranged as 'oioio'
 *
 * Input  : 'yuyuo'
 * Output :  No                                                              */

bool palindrome(std::string s);

int main()
{
  std::string S = "aaaddad";
  (palindrome(S))?  std::cout << "Yes\n" : std::cout << "No\n";
  return 0;
}

bool palindrome(std::string S)
{
  // length of the string
  int n = S.length();

  // to count number of distinct character in string
  std::set<char> counting;

  // to count frequency of each character
  std::map<char, int> MAP;
  for (int i = 0; i < n; ++i)
  {
    counting.insert(S[i]);
    MAP[S[i]] += 1;
  }
  if (counting.size() == 1)
  {
    return true;  // if all characters in the string are same
  }
  if (counting.size() > 2)
  {
    return false;  // if there are more than 2 different character in string
  }
  
  // currently there is 2 different character in string
  auto iterator = counting.begin();

  // get the frequencies of the character that present in string
  int x = 0, y = 0;
  x = MAP[*iterator];

  iterator++;
  y = MAP[*iterator];

  // difference between their count is less that or equal to 1
  if (abs(x - y) <= 1)
  {
    return true;
  }
  return false;
}