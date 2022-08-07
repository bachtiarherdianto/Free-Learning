#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// Checking whether two strings are permutation of each other
#define NO_OF_CHARS 256 // for method2 and method3

class Permutation
{
public:
  bool method1(string str1, string str2);
  /* Method 1:
   * - Sort both strings
   * - Compare the sorted strings */

  bool method2(string str1, string str2);
  /* Method 2:
   * - Create count arrays of size 256 for both strings.
   *   Initialize all values in count arrays as 0.
   * - Iterate through every character of both strings and
   *   increment the count of character in the corresponding
   *   count arrays.
   * - Compare count arrays. If both count arrays are same,
   *   the return true.                                     */

  bool method3(string str1, string str2);
  /* Method 3 (optimization of Method 2)
   * The implementation of Method 2 can be further to use only one
   * count arrays instead of two. We can increment the value in count
   * array for characters in string1 and decrement fo character in string2.
   * Finnaly, if all count values are 0, then the two strings are
   * Permutation of each other                                           */
};

int main()
{
  string arr1 = "geeksforgeeks";
  string arr2 = "forgeeksgeeks";

  Permutation checks;

  // (checks.method1(arr1, arr2))?
  (checks.method2(arr1, arr2))? 
  // (checks.method3(arr1, arr2))?  
  cout << "Yes\n" : cout << "No\n";

  return 0;
}

bool Permutation::method1(string str1, string str2)
{
  // get lengths of both strings
  int n1 = str1.length();
  int n2 = str2.length();

  // check whether the lengths is same
  if (n1 != n2)
  {
    return false;
  }

  // sort both string
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  // compare the sorted strings
  for (int i = 0; i < n1; ++i)
  {
    if (str1[i] != str2[i])
    {
      return false;
    }
  }
  return true;
}

bool Permutation::method2(string str1, string str2)
{
  // create 2 count arrays and initialize all values as 0
  int count1[NO_OF_CHARS] = {0};
  int count2[NO_OF_CHARS] = {0};
  int i;

  // for each character in input strings, increment count
  // in the corresponding count array
  for (i = 0; str1[i] && str2[i]; ++i)
  {
    count1[str1[i]]++;
    count2[str2[i]]++;
  }

  // if both strings are of different length, removing this
  // condition will make the program fail for strings
  // like "aaca" and "aca"
  if (str1[i] || str2[i])
  {
    return false;
  }

  // compare count arrays
  for (i = 0; i < NO_OF_CHARS; ++i)
  {
    if (count1[i] != count2[i])
    {
      return false;
    }
  }
  return true;
}

bool Permutation::method3(string str1, string str2)
{
  // create a count arrays and initialize all values as 0
  int counting[NO_OF_CHARS] = {0};
  int i;

  // for each character in input strings, increment count
  // in the corresponding count array
  for (i = 0; str1[i] && str2[i]; ++i)
  {
    counting[str1[i]]++;
    counting[str2[i]]--;
  }

  // if both strings are of different length, removing this
  // condition will make the program fail for strings
  // like "aaca" and "aca"
  if (str1[i] || str2[i])
  {
    return false;
  }

  // see whether there is any non-zero value in count array
  for (i = 0; i < NO_OF_CHARS; ++i)
  {
    if (counting[i])
    {
      return false;
    }
  }
  return true;
}