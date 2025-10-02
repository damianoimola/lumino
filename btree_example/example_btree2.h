//
// Created by damiano on 28/09/25.
//
#pragma once

#include "behaviortree_cpp/bt_factory.h"
#include <iostream>
#include <string>

#include "base_btree.h"


// ########################################################
// ###    TREE                                          ###
// ########################################################

class MainTree : BaseBTree
{
public:
    MainTree()= default;
    ~MainTree()= default;
    void register_tree(BT::BehaviorTreeFactory *factory) override;
};




// ########################################################
// ###    METHODS                                       ###
// ########################################################

// this class read a const message or a port-exposed message
class SaySomething : public BT::SyncActionNode
{
public:
    SaySomething(const std::string& name, const BT::NodeConfig& config) : BT::SyncActionNode(name, config) {}

    BT::NodeStatus tick() override;

    static BT::PortsList providedPorts();
};


// this class exposes a message to a port
class ThinkWhatToSay : public BT::SyncActionNode
{
public:
    ThinkWhatToSay(const std::string& name, const BT::NodeConfig& config) : BT::SyncActionNode(name, config) {}

    BT::NodeStatus tick() override;

    static BT::PortsList providedPorts();
};


// this class exposes a message to a port
class ThinkWhatToSay2 : public BT::SyncActionNode
{
public:
    ThinkWhatToSay2(const std::string& name, const BT::NodeConfig& config) : BT::SyncActionNode(name, config) {}

    BT::NodeStatus tick() override;

    static BT::PortsList providedPorts();
};