#include <iostream>
#include <vector>
#include <string>
#include "pugixml.hpp"

struct Node {
    std::string id;
    std::string label;
};

struct Edge {
    std::string id;
    std::string source;
    std::string target;
};

int main() {
    pugi::xml_document doc;
    
    pugi::xml_parse_result result = doc.load_file("LesMiserables.gexf");
    if (!result) {
        std::cerr << "Erro ao abrir o arquivo GEXF: " << result.description() << std::endl;
        return 1;
    }

    pugi::xml_node graph_node = doc.child("gexf").child("graph");
    
    if (!graph_node) {
        std::cerr << "Estrutura GEXF inválida (falta a tag <graph>)." << std::endl;
        return 1;
    }

    std::vector<Node> nodes;
    std::vector<Edge> edges;

    pugi::xml_node nodes_container = graph_node.child("nodes");
    for (pugi::xml_node node : nodes_container.children("node")) {
        Node n;
        n.id = node.attribute("id").as_string();
        n.label = node.attribute("label").as_string();
        nodes.push_back(n);
    }

    pugi::xml_node edges_container = graph_node.child("edges");
    for (pugi::xml_node edge : edges_container.children("edge")) {
        Edge e;
        e.id = edge.attribute("id").as_string();
        e.source = edge.attribute("source").as_string();
        e.target = edge.attribute("target").as_string();
        edges.push_back(e);
    }

    std::cout << "--- NÓS ENCONTRADOS (" << nodes.size() << ") ---\n";
    for (const auto& n : nodes) {
        std::cout << "ID: " << n.id << " | Label: " << n.label << "\n";
    }

    std::cout << "\n--- ARESTAS ENCONTRADAS (" << edges.size() << ") ---\n";
    for (const auto& e : edges) {
        std::cout << "Edge ID: " << e.id << " (" << e.source << " -> " << e.target << ")\n";
    }

    return 0;
}
