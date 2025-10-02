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

class GeneralBTree : BaseBTree
{
public:
    GeneralBTree()= default;
    ~GeneralBTree()= default;
    void register_tree(BT::BehaviorTreeFactory *factory) override;
};





// ########################################################
// ###    METHODS                                       ###
// ########################################################
class DisplayTime : public BT::SyncActionNode {
public:
    explicit DisplayTime(const std::string& name) : BT::SyncActionNode(name, {}) {};

    // mandatory
    BT::NodeStatus tick() override;
};