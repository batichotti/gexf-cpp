#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include "pugixml.hpp"
#include "graph.hpp"

// Importa o arquivo .gexf e verifica sua integridade
bool load_file(const char* path, pugi::xml_document& doc);

// Localiza a tag <graph> dentro do documento
pugi::xml_node find_graph_node(const pugi::xml_document& doc);

// Lê os <node> e adiciona ao grafo
void parse_nodes(const pugi::xml_node& graph_node, Graph& g);

// Lê os <edge> e adiciona ao grafo
void parse_edges(const pugi::xml_node& graph_node, Graph& g);

// Lê um arquivo .gexf
std::optional<Graph> read_gexf(const char* path);

// Exibe informações
void print_graph(const Graph& g);