#include "read_file.cpp"
#include <string>

int closeness_centrality(Graph graph, Node node, float dist = 0, std::unordered_set<std::string> visited = {}){
    auto neighbours =  graph.neighbours(node);
}

int main() {
    auto g = read_gexf("LesMiserables.gexf").value();

    const auto& nodes = g.nodes();
    const auto& edges = g.edges();

    for (const auto& n : nodes){
        const auto& neighbours = g.neighbours(n);
        int closeness = closeness_centrality(g, n);
    }

    return 0;
}
