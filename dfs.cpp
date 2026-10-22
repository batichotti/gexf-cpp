#include "dfs.hpp"

DepthFirstSearch::DepthFirstSearch(const Graph& g, Node n){
    marked_.clear();
    count_ = 0;
    dfs(g, n);
}

void DepthFirstSearch::dfs(const Graph& g, Node n) {
    marked_.insert(n);
    count_++;

    for (Node nei : g.neighbours(n))
        if (marked_.find(nei) == marked_.end()) dfs(g, nei);
}