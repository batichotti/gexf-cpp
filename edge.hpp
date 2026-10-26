#pragma once
#include <string>
#include <functional>

class Edge {
    public:
        Edge(std::string id, std::string source, std::string target) : id_(id), source_(source), target_(target) {}

        const std::string& id() const { return id_; }
        const std::string& source() const { return source_; }
        const std::string& target() const { return target_; }

        bool operator==(const Edge& other) const { return id_ == other.id_; }

    private:
        std::string id_, source_, target_;
};

namespace std {
template <>
struct hash<Edge> {
    size_t operator()(const Edge& e) const noexcept {
        return hash<string>{}(e.id());
    }
};
}