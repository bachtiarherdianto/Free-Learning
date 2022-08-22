#include <iostream>
#include <vector>
#include <utility>

/*
 * Boruvka's algorithm for solving Minimum Spanning Tree
 */

/* Pseudocode:
 * Initialize a forest T that constains one vertex-trees, one for each vertex of the graph
 * while size(T) > 1:
 *    for each element C of T
 *        Create an empty set of edges S
 *        for each vertex 'v' \in C
 *            Find the least weight edge 'e' from v to a vertex u \in C
 *            Add 'e' into S
 *        Add the smallest weighted edge 'e' \in S to T
 * T is the final minimum spanning tree of the given graph
 * Display output T
 */

int find_root(std::vector<std::pair<int, int>>& trees, int i){
    if (trees[i].second != i) trees[i].second = find_root(trees, trees[i].second);
    return trees[i].second;
}

void union_trees(std::vector<std::pair<int, int>>& trees, int a, int b){
    int root_a = find_root(trees, a);
    int root_b = find_root(trees, b);

    // merge trees by comparing rank
    if (trees[root_a].first < trees[root_b].first){
        trees[root_a].second = root_b;
    }else if (trees[root_a].first > trees[root_b].first){
        trees[root_b].second = root_a;
    }else{
        trees[root_b].second = root_a;
        trees[root_a].first++;
    }
}

int solution(std::vector<std::vector<int>> graph, int v, int e){
    auto trees = std::vector<std::pair<int, int>>();

    for (int i = 0; i < v; ++i) trees.push_back(std::make_pair(0, i));

    int total_trees = v;
    int total_weight = 0;

    while(total_trees > 1){
        auto smallest_edge = std::vector<int>(v, -1);

        for (int i = 0; i < e; ++i){
            int set_a = find_root(trees, graph[i][0]);
            int set_b = find_root(trees, graph[i][1]);

            if (set_a == set_b){
                continue;
            }else{
                if (smallest_edge[set_a] == -1 || graph[smallest_edge[set_a]][2] > graph[i][2]) smallest_edge[set_a] = i;

                if (smallest_edge[set_b] == -1 || graph[smallest_edge[set_b]][2] > graph[i][2]) smallest_edge[set_b] = i;
            }
        }

        for(int i = 0; i < v; ++i){    // calculate MST
            if (smallest_edge[i] != -1){
                int set_a = find_root(trees, graph[smallest_edge[i]][0]);
                int set_b = find_root(trees, graph[smallest_edge[i]][1]);

                if (set_a == set_b) continue;

                total_weight += graph[smallest_edge[i]][2];

                // if two trees are not same then do the union and decrement the no of trees
                union_trees(trees, set_a, set_b);
                total_trees--;
            }
        }
    }

    return total_weight;
}

int main(){
    int v = 5;      // no of vertices
    int e = 6;      // no of edges
    
    auto graph = std::vector<std::vector<int>>();
    
    // edge (1, 2): weight = 3
    graph.push_back({1, 2, 3});

    // edge (1, 4): weight = 4
    graph.push_back({1, 4, 4});

    // edge (1, 5): weight = 13
    graph.push_back({1, 5, 13});

    // edge (2, 3): weight = 9
    graph.push_back({2, 3, 9});

    // edge (5, 3): weight = 2
    graph.push_back({5, 3, 2});

    // edge (3, 4): weight = 8
    graph.push_back({3, 4, 8});

    std::cout << "Total Weight = " << solution(graph, v, e) << std::endl;;
    return 0;
}