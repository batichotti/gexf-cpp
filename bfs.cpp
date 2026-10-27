#include "bfs.hpp"

#include <algorithm>

BreadthFirstPaths::BreadthFirstPaths(const Graph& G, const Node& s) : s_(s) { bfs(G, s); }

void BreadthFirstPaths::bfs(const Graph& G, const Node& s) {

    std::queue<Node> queue;

    marked_.insert(s);

    queue.push(s);

    while (!queue.empty()) {
        Node v = queue.front();
        queue.pop();

        for (const Node& w : G.neighbours(v))
            if (marked_.find(w) == marked_.end()) {
                edgeTo_.insert({w, v});
                marked_.insert(w);
                queue.push(w);
            }
    }
}


bool BreadthFirstPaths::hasPathTo(const Node& v) const { return marked_.find(v) != marked_.end(); }


std::vector<Node> BreadthFirstPaths::pathTo(const Node& v) const {
    std::vector<Node> path;
    if (!hasPathTo(v)) return path;

    Node current = v;
    while (!(current == s_)) {
        path.push_back(current);
        current = edgeTo_.at(current);
    }

    path.push_back(s_);
    std::reverse(path.begin(), path.end());

    return path;
}