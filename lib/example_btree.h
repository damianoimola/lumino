//
// Created by damiano on 28/09/25.
//
#pragma once


#include "behaviortree_cpp/bt_factory.h"
#include <iostream>
#include <string>

class ApproachObject : public BT::SyncActionNode {
public:
    ApproachObject(const std::string& name) : BT::SyncActionNode(name, {}) {};

    // mandatory
    BT::NodeStatus tick() override;
};


BT::NodeStatus CheckBattery();


class GripperInterface
{
public:
    GripperInterface(): _open(true) {}
    BT::NodeStatus open();
    BT::NodeStatus close();
private:
    bool _open; // shared information
};

