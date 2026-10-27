    #pragma once

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "graph.hpp"

class BreadthFirstPaths {
    public:
        BreadthFirstPaths(const Graph& G, const Node& s);

        bool hasPathTo(const Node& v) const;
        std::vector<Node> pathTo(const Node& v) const;

    private:
        std::unordered_set<Node> marked_;
        std::unordered_map<Node, Node> edgeTo_;
        Node s_;

        void bfs(const Graph& G, const Node& s);
};