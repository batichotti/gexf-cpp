#include <vector>
#include <unordered_set>
#include "graph.cpp"

class DepthFirstSearch {
    public:
        const bool marked(Node n) const { return (marked_.find(n) != marked_.end()) ? 1 : 0; }
        const int count() const { return count_; }
    
        DepthFirstSearch(Graph g, Node n){
            marked_.clear();
            count_ = 0;
            dfs(g, n);
        }

    private:
        std::unordered_set<Node> marked_;
        int count_;

        void dfs(const Graph& g, Node n) {
            marked_.insert(n);
            count_++;

            for (Node nei : g.neighbours(n))
                if (marked_.find(nei) == marked_.end()) dfs(g, nei);
        }
};