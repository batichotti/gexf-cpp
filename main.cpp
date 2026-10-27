#include "read_file.cpp"
#include "eccentricity.cpp"
#include "closeness.cpp"
#include <fstream>

int main() {
    Graph g = read_gexf("LesMiserables.gexf").value();

    std::vector<std::pair<std::string, double>> closeness;
    for (const auto& [id, node] : g.nodes())
        closeness.emplace_back(id, closeness_centrality(g, node));

    for (const auto& [id, value] : closeness)
        std::cout << "Nó: " << id
                  << " -> Closeness Centrality: " << value << '\n';

    std::unordered_map<std::string, int> ecc;
    for (const auto& [id, n] : g.nodes())
        ecc[id] = eccentricity(g, n);

    for (const auto& [id, value] : ecc)
        std::cout << "Nó: " << id
                  << " -> Eccentricity: " << value << '\n';

    std::ofstream cc_f("Closeness_Centrality.txt", std::ios::out | std::ios::trunc);
    std::ofstream ecc_f("Eccentricity.txt", std::ios::out | std::ios::trunc);

    if (cc_f.is_open() && ecc_f.is_open()) {
        for(const auto& [id, value] : closeness)
            cc_f << id << ": " << value << std::endl;

        for(const auto& [id, value] : ecc)
            ecc_f << id << ": " << value << std::endl;
        
        cc_f.close();
        ecc_f.close();
    } else std::cout << "Erro ao abrir os arquivos de saída" << std::endl;

    return 0;
}