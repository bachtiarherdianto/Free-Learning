#include <iostream>
#include <algorithm>

/* Fractional Knapsack Prolem
 * 
 * Input:
 * Item as (value, weight) arr[] = {{60, 10}, {100, 20}, {120, 30}}
 * Capacity, W = 50;
 *
 * Output:
 * Maximum possible value = 240
 * by taking item of weight 10 and 20, and 2/3 of 30               */

struct Item
  {
    int value, weight;
    Item(int value, int weight): value(value), weight(weight)
    {}
  };  

bool cmp(struct Item a, struct Item b);

void FractionalKnapsack(int W, struct Item arr[], int n);

int main()
{
  int W = 50;
  Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(arr)/sizeof(arr[0]);

  FractionalKnapsack(W, arr, n);
  return 0;
}

bool cmp(struct Item a, struct Item b)
{
  float r1 = (float)a.value / a.weight;
  float r2 = (float)b.value / b.weight;
  return r1 > r2;
}

void FractionalKnapsack(int W, struct Item arr[], int n)
{
  std::sort(arr, arr + n, cmp);

  std::cout << "Order of Ratio of Items:\n";
  for (int i = 0; i < n; ++i)
  {
    std::cout << "value: "    << arr[i].value
              << "; weight: " << arr[i].weight
              << "; ration: " << ((float)arr[i].value/arr[i].weight) << std::endl; 
  }

  int curWeight = 0; 
  float finalvalue = 0.0;

  for (int i = 0; i < n; ++i)
  {
    if (curWeight + arr[i].weight <= W)
    {
      curWeight += arr[i].weight;
      finalvalue += arr[i].value;
    }
    else
    {
      int remain = W - curWeight;
      finalvalue += arr[i].value * ((float)remain / arr[i].weight);
      break;
    }
  }

  std::cout << "\nMaximum possible value:\n"
            << finalvalue << std::endl;
}