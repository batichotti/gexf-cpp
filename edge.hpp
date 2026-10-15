#pragma once
#include <string>

class Edge {
    public:
        Edge(std::string id, std::string source, std::string target) : id_(id), source_(source), target_(target) {}

        const std::string& id() const { return id_; }
        const std::string& source() const { return source_; }
        const std::string& target() const { return target_; }

    private:
        std::string id_, source_, target_;
};