#pragma once

#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class HierarchyNode {
public:
    HierarchyNode(const std::string& name) : name(name) {}

    void addChild(std::shared_ptr<HierarchyNode> child) {
        children.push_back(child);
    }

    const std::vector<std::shared_ptr<HierarchyNode>>& getChildren() const {
        return children;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    std::vector<std::shared_ptr<HierarchyNode>> children;
};

#endif // HIERARCHY_NODE_H
