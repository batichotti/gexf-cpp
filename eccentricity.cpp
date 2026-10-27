#include "read_file.hpp"
#include "graph.hpp"
#include "bfs.hpp"

int eccentricity(const Graph& G, const Node& s){
    int max_dist = 0;
    
    BreadthFirstPaths bfs(G, s);

    for(const auto& [id, n] : G.nodes()){
        int dist = bfs.pathTo(n).size() - 1;
        max_dist = (dist > max_dist) ? dist : max_dist;
    }

    return max_dist;
}