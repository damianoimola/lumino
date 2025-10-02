//
// Created by damiano on 02/10/25.
//

#include "general_btree.h"

// ########################################################
// ###    TREE                                          ###
// ########################################################
void GeneralBTree::register_tree(BT::BehaviorTreeFactory *factory) {
    factory->registerNodeType<DisplayTime>("DisplayTime");
}






// ########################################################
// ###    METHODS                                       ###
// ########################################################
NodeStatus DisplayTime::tick() {
    auto current_time = std::chrono::system_clock::now();

    std::cout << "The current time is: " << current_time << std::endl;
    return BT::NodeStatus::SUCCESS;
}