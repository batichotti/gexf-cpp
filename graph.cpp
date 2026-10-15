#include "graph.hpp"

void Graph::build_adjacency(){
    this->adj_.clear();

    for (Edge edge : edges_) {
        this->adj_[edge.source()].insert(edge.target());
        this->adj_[edge.target()].insert(edge.source());
    }
}