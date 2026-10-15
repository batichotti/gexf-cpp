#pragma once

#include <vector>
#include <unordered_set>
#include "graph.cpp"

class DepthFirstSearch {
    public:
        const bool marked(Node n) const { return (marked_.find(n) != marked_.end()) ? 1 : 0; }
        const int count() const { return count_; }
    
        DepthFirstSearch(const Graph&, Node n);

    private:
        std::unordered_set<Node> marked_;
        int count_;

        void dfs(const Graph& g, Node n);
};