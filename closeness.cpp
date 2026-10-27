#include "read_file.hpp"
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

double closeness_centrality(const Graph& graph, const Node& start) {
    std::queue<const Node*> queue;
    std::unordered_map<std::string, int> distances;

    queue.push(&start);
    distances[start.id()] = 0;

    long long total_dist = 0;
    int reachable = 0;

    while (!queue.empty()) {
        const Node* current = queue.front();
        queue.pop();
        int d = distances[current->id()];

        for (const Node& neighbour : graph.neighbours(*current)) {
            if (distances.find(neighbour.id()) == distances.end()) {
                distances[neighbour.id()] = d + 1;
                total_dist += d + 1;
                reachable++;
                queue.push(&neighbour);
            }
        }
    }

    if (total_dist == 0) return 0.0;

    double n = static_cast<double>(graph.nodes().size());
    return (static_cast<double>(reachable) / total_dist) * (reachable / (n - 1));
}

// int main() {
//     auto g = read_gexf("LesMiserables.gexf").value();

//     std::vector<std::pair<std::string, double>> closeness;
//     for (const auto& [id, node] : g.nodes())
//         closeness.emplace_back(id, closeness_centrality(g, node));

//     for (const auto& [id, value] : closeness)
//         std::cout << "Nó: " << id
//                   << " -> Closeness Centrality: " << value << '\n';

//     return 0;
// }