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
};