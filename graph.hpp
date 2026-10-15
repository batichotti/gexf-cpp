#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "node.hpp"
#include "edge.hpp"

class Graph {
    public:
        void add_node(Node n) { nodes_.push_back(n); }
        void add_edge(Edge e) { edges_.push_back(e); }

        const std::vector<Node>& nodes() const { return nodes_; }
        const std::vector<Edge>& edges() const { return edges_; }

        void build_adjacency();

    private:
        std::vector<Node> nodes_;
        std::vector<Edge> edges_;
        std::unordered_map<std::string, std::unordered_set<std::string>> adj_;
};