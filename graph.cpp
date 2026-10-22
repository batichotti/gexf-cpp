#include "graph.hpp"

void Graph::build_adjacency(){
    this->adj_.clear();
    for (const auto& [id, node] : nodes_) adj_.try_emplace(node);
    for (Edge edge : this->edges_) {
        if (nodes_.find(edge.source()) != nodes_.end()){
            this->adj_[nodes_.at(edge.source())].insert(nodes_.at(edge.target()));
            this->adj_[nodes_.at(edge.target())].insert(nodes_.at(edge.source()));
        }
    }
}