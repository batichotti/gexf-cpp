#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include "pugixml.hpp"
#include "graph.cpp"

// Importa o arquivo .gexf e verifica sua integridade
bool load_file(const char* path, pugi::xml_document& doc){
    pugi::xml_parse_result result = doc.load_file(path);
    
    // result verifica se a importação foi bem-sucedida
    if (!result) {
        std::cerr << "Erro ao abrir o arquivo GEXF: " << result.description() << std::endl;
        return false;
    }

    return true;
}

// Localiza a tag <graph> dentro do documento
pugi::xml_node find_graph_node(const pugi::xml_document& doc) {
    return doc.child("gexf").child("graph");
}

// Lê os <node> e adiciona ao grafo
void parse_nodes(const pugi::xml_node& graph_node, Graph& g) {
    for (pugi::xml_node node : graph_node.child("nodes").children("node")) {
        g.add_node(Node(node.attribute("id").as_string(),
                        node.attribute("label").as_string()));
    }
}

// Lê os <edge> e adiciona ao grafo
void parse_edges(const pugi::xml_node& graph_node, Graph& g) {
    for (pugi::xml_node edge : graph_node.child("edges").children("edge")) {
        g.add_edge(Edge(edge.attribute("id").as_string(),
                        edge.attribute("source").as_string(),
                        edge.attribute("target").as_string()));
    }
}

// Unifica os processos anteriores
std::optional<Graph> read_gexf(const char* path) {
    pugi::xml_document doc;
    if (!load_file(path, doc)) return std::nullopt;

    pugi::xml_node graph_node = find_graph_node(doc);
    if (!graph_node) {
        std::cerr << "Estrutura gexf inválida (falta a tag <graph>)." << std::endl;
        return std::nullopt;
    }

    Graph g;
    parse_nodes(graph_node, g);
    parse_edges(graph_node, g);
    g.build_adjacency();
    return g;
}

// Exibe informações
void print_graph(const Graph& g) {
    const auto& nodes = g.nodes();
    const auto& edges = g.edges();
    
    std::cout << "--- NÓS ENCONTRADOS (" << nodes.size() << ") ---\n";
    for (const auto& n : nodes)
    std::cout << "ID: " << n.id() << " | Label: " << n.label() << "\n";
    
    std::cout << "\n--- ARESTAS ENCONTRADAS (" << edges.size() << ") ---\n";
    for (const auto& e : edges)
    std::cout << "Edge ID: " << e.id() << " (" << e.source() << " -> " << e.target() << ")\n";
    
    std::cout << "\n--- MAPA DE ADJACÊNCIAS ---\n";
    for (const auto& n : nodes){
        std::cout << "ID: " << n.id() << " | Label: " << n.label() << " -> \n";
        const auto& neighbours = g.neighbours(n);
        for (const auto& nei : neighbours)
            std::cout << "      ID: " << nei << " -> \n";
    }
}

int main() {
    auto g = read_gexf("LesMiserables.gexf");
    if (!g) return 1;

    print_graph(*g);

    return 0;
}
