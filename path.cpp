#include "path.h"
#include <iostream>

Path::Path() : path_{}, cost_{0} {}

Path::Path(std::vector<int> path, int cost)
        : path_{std::move(path)}, cost_{cost} {}

void Path::add_to_path(int node, int cost) {
    path_.push_back(node);
    cost_ += cost;
}

int Path::get_prev_city() const {
    if (!path_.empty()) {
        return path_.back();
    }
    return -1; // Or throw an exception
}

std::string Path::to_string() const {
    return "Path: " + get_path_str() + ", Cost: " + get_cost_str();
}

std::string Path::get_path_str() const {
    std::string output;
    for (size_t i = 0; i < path_.size(); ++i) {
        output += std::to_string(path_[i]);
        if (i < path_.size() - 1) output += "->";
    }
    return output;
}

std::string Path::get_cost_str() const {
    return std::to_string(cost_);
}