#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

/* Travelling Salesman Problem
 * solve using naive approach  */
#define V 4

int TSP(int graph[][V], int s);

int main()
{
  int matrices[][V] = {{0, 10, 15, 20},
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0}};
  int s = 0;

  std::cout << "Optimum Total Distance = " 
            << TSP(matrices, s) << std::endl;
  return 0;
}

int TSP(int graph[][V], int s)
{
  std::vector<int> vertex;
  for (int i = 0; i < V; ++i)
  {
    if (i != s)
    {
      vertex.push_back(i);
    }
  }

  int min_path = INT_MAX;
  do
  {
    int current_pathweight = 0;
    int k = s;
    for (int i = 0; i < vertex.size(); ++i)
    {
      current_pathweight += graph[k][vertex[i]];
      k = vertex[i];
    }

    current_pathweight += graph[k][s];
    min_path = std::min(min_path, current_pathweight);
  } while (next_permutation(vertex.begin(), vertex.end()));

  return min_path;
}