//
// Created by damiano on 02/10/25.
//

#include "initial_btree.h"



// ########################################################
// ###    TREE                                          ###
// ########################################################
void InitialBTree::register_tree(BT::BehaviorTreeFactory *factory) {
    factory->registerNodeType<WakeUp>("WakeUp");
    factory->registerNodeType<Wave>("Wave");
}






// ########################################################
// ###    METHODS                                       ###
// ########################################################
NodeStatus WakeUp::tick() {
    std::cout << "Waking Up: " << this->name() << std::endl;
    return BT::NodeStatus::SUCCESS;
}

NodeStatus Wave::tick() {
    std::cout << "Waving: " << this->name() << std::endl;
    return BT::NodeStatus::SUCCESS;
}