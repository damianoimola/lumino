//
// Created by damiano on 02/10/25.
//
#pragma once

using namespace BT;

class BaseBTree {
public:
    virtual void register_tree(BT::BehaviorTreeFactory *factory) = 0;
};
