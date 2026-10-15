#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "node.hpp"
#include "edge.hpp"

class Graph {
    public:
        void add_node(Node n) { nodes_.insert({n.id(), n}); }
        void add_edge(Edge e) { edges_.insert(e); }

        const std::unordered_map<std::string, Node>& nodes() const { return nodes_; }
        const std::unordered_set<Edge>& edges() const { return edges_; }
        const std::unordered_map<Node, std::unordered_set<Node>>& adj() const { return adj_; }
        const std::unordered_set<Node>& neighbours(Node n) const { return adj_.at(n); }

        void build_adjacency(){
            this->adj_.clear();
            for (Edge edge : this->edges_) {
                if (nodes_.find(edge.source()) != nodes_.end())
                    this->adj_[nodes_.at(edge.source())].insert(nodes_.at(edge.target()));
                    this->adj_[nodes_.at(edge.target())].insert(nodes_.at(edge.source()));
           }
        }

    private:
        std::unordered_map<std::string, Node> nodes_;
        std::unordered_set<Edge> edges_;
        std::unordered_map<Node, std::unordered_set<Node>> adj_;
};