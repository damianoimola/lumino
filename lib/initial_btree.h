//
// Created by damiano on 02/10/25.
//
#pragma once
#include "behaviortree_cpp/bt_factory.h"
#include "base_btree.h"

using namespace BT;

// ########################################################
// ###    TREE                                          ###
// ########################################################

class InitialBTree : BaseBTree
{
public:
    InitialBTree()= default;
    ~InitialBTree()= default;
    void register_tree(BT::BehaviorTreeFactory *factory) override;
};





// ########################################################
// ###    METHODS                                       ###
// ########################################################
class WakeUp : public BT::SyncActionNode {
public:
    explicit WakeUp(const std::string& name) : BT::SyncActionNode(name, {}) {};

    // mandatory
    BT::NodeStatus tick() override;
};


class Wave : public BT::SyncActionNode {
public:
    explicit Wave(const std::string& name) : BT::SyncActionNode(name, {}) {};

    // mandatory
    BT::NodeStatus tick() override;
};
