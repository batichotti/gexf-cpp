#pragma once
#include <string>
#include <utility>
#include <functional>

class Node {
public:
    Node(std::string id, std::string label)
        : id_(std::move(id)), label_(std::move(label)) {}

    const std::string& id() const { return id_; }
    const std::string& label() const { return label_; }

    bool operator==(const Node& other) const { return id_ == other.id_; }

private:
    std::string id_, label_;
};

namespace std {
template <>
struct hash<Node> {
    size_t operator()(const Node& n) const noexcept {
        return hash<string>{}(n.id());
    }
};
}