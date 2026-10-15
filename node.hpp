#pragma once
#include <string>

class Node {
    public:
        Node(std::string id, std::string label) : id_(id), label_(label) {}

        const std::string& id() const { return id_; }
        const std::string& label() const { return label_; }

        
        private:
            std::string id_;
            std::string label_;
            bool operator==(const Node& other) const { return this->id() == other.id(); }
        
};

namespace std {
    template <>
    struct hash<Node> {
        size_t operator()(const Node& n) const {
            // Gera o hash com base na string retornada por id()
            return hash<string>()(n.id()); 
        }
    };
}