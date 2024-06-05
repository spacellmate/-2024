/*BSF_Algorithm*/
#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
    virtual bool operator==(const Node& other) const = 0;
    virtual bool is_the_solution(const Node& state) const = 0;
    virtual std::vector<Node*> extend_node() const = 0;
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual ~Node() = default;
};

class BFS {
private:
    const Node* start_state;
    const Node* final_state;
    std::vector<const Node*> frontier;
    std::vector<const Node*> checked_nodes;
    int number_of_steps;
    std::vector<const Node*> path;

public:
    BFS(const Node* start, const Node* final) : start_state(start), final_state(final) {
        frontier.push_back(start_state);
        number_of_steps = 0;
    }

    void insert_to_frontier(const Node* node) {
        frontier.push_back(node);
    }

    const Node* remove_from_frontier() {
        const Node* first_node = frontier.front();
        frontier.erase(frontier.begin());
        checked_nodes.push_back(first_node);
        return first_node;
    }

    bool frontier_is_empty() {
        return frontier.empty();
    }

    void search() {
        while (true) {
            number_of_steps++;

            if (frontier_is_empty()) {
                std::cout << "No Solution Found after " << number_of_steps << " steps!!!" << std::endl;
                break;
            }

            const Node* selected_node = remove_from_frontier();

            if (selected_node->is_the_solution(*final_state)) {
                std::cout << "Solution Found in " << number_of_steps << " steps" << std::endl;
                selected_node->print(std::cout);
                break;
            }

            std::vector<const Node*> new_nodes = selected_node->extend_node();

            for (const auto& new_node : new_nodes) {
                if (std::find(frontier.begin(), frontier.end(), new_node) == frontier.end() &&
                    std::find(checked_nodes.begin(), checked_nodes.end(), new_node) == checked_nodes.end()) {
                    insert_to_frontier(new_node);
                }
            }
        }
    }
};

/*main*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class MazeNode : public Node {
private:
    std::string state;
public:
    MazeNode(const std::string& s) : state(s) {}

    bool operator==(const Node& other) const override {
        const MazeNode& other_node = dynamic_cast<const MazeNode&>(other);
        return state == other_node.state;
    }

    bool is_the_solution(const Node& state) const override {
        const MazeNode& final_state = dynamic_cast<const MazeNode&>(state);
        return *this == final_state;
    }

    std::vector<Node*> extend_node() const override {
        std::vector<Node*> new_nodes;
        if (state == "A") {
            new_nodes.push_back(new MazeNode("S"));
        } else if (state == "B") {
            new_nodes.push_back(new MazeNode("C"));
            new_nodes.push_back(new MazeNode("D"));
            new_nodes.push_back(new MazeNode("S"));
        }
        return new_nodes;
    }

    std::ostream& print(std::ostream& os) const override {
        os << state;
        return os;
    }
};

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"S"}},
        {"B", {"C", "D", "S"}},
        {"C", {"B", "J"}},
        {"D", {"B", "G", "S"}},
        {"E", {"G", "S"}},
        {"F", {"G", "H"}},
        {"G", {"D", "E", "F", "H", "J"}},
        {"H", {"F", "G", "I"}},
        {"I", {"H", "J"}},
        {"J", {"C", "G", "I"}},
        {"S", {"A", "B", "D", "E"}}
    };

    MazeNode* start_node = new MazeNode("S");
    MazeNode* final_node = new MazeNode("I");
    BFS bfs(start_node, final_node);
    bfs.search();

    return 0;
}

/*maze*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class MazeNode : public Node {
private:
    std::string value;
    MazeNode* parent;
    std::unordered_map<std::string, std::vector<std::string>> graph;

public:
    MazeNode(const std::unordered_map<std::string, std::vector<std::string>>& g, const std::string& v) : graph(g), value(v), parent(nullptr) {}

    bool operator==(const Node& other) const override {
        const MazeNode& other_node = dynamic_cast<const MazeNode&>(other);
        return value == other_node.value;
    }

    bool is_the_solution(const Node& state) const override {
        const MazeNode& final_state = dynamic_cast<const MazeNode&>(state);
        return value == final_state.value;
    }

    std::vector<Node*> extend_node() const override {
        std::vector<Node*> children;
        for (const auto& child_value : graph.at(value)) {
            auto child = new MazeNode(graph, child_value);
            child->parent = const_cast<MazeNode*>(this);
            children.push_back(child);
        }
        return children;
    }

    std::vector<std::string> find_path() {
        std::vector<std::string> path;
        const MazeNode* current_node = this;
        while (current_node->parent != nullptr) {
            path.insert(path.begin(), current_node->value);
            current_node = current_node->parent;
        }
        path.insert(path.begin(), current_node->value);
        return path;
    }

    std::string to_string() const {
        std::vector<std::string> total_path = find_path();
        std::string path;
        for (size_t index = 0; index < total_path.size(); ++index) {
            if (index == total_path.size() - 1) {
                path += total_path[index] + " ";
            } else {
                path += total_path[index] + " -> ";
            }
        }
        return path + "\nPath length: " + std::to_string(total_path.size() - 1);
    }
};