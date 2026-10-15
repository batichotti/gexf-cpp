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
        const std::unordered_map<std::string, std::unordered_set<std::string>>& adj() const { return adj_; }
        const std::unordered_set<std::string>& neighbours(Node n) const { return adj_.at(n.id()); }

        void build_adjacency(){
            this->adj_.clear();
            for (Edge edge : this->edges_) {
                this->adj_[edge.source()].insert(edge.target());
                this->adj_[edge.target()].insert(edge.source());
           }
        }

    private:
        std::vector<Node> nodes_;
        std::vector<Edge> edges_;
        std::unordered_map<std::string, std::unordered_set<std::string>> adj_;
};