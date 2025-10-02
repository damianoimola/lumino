//
// Created by damiano on 28/09/25.
//

#include "example_btree.h"


using namespace BT;


// ########################################################
// ###    TREE                                          ###
// ########################################################
void GraspObjectTree::register_tree(BT::BehaviorTreeFactory *factory) {
    factory->registerNodeType<ApproachObject>("ApproachObject");
    factory->registerSimpleCondition("CheckBattery", [&](BT::TreeNode&) { return CheckBattery(); });
    GripperInterface gripper;
    factory->registerSimpleAction("OpenGripper", [&](BT::TreeNode&){ return gripper.open(); } );
    factory->registerSimpleAction("CloseGripper", [&](BT::TreeNode&){ return gripper.close(); } );
}






// ########################################################
// ###    METHODS                                       ###
// ########################################################
NodeStatus ApproachObject::tick() {
    std::cout << "ApproachObject: " << this->name() << std::endl;
    return BT::NodeStatus::SUCCESS;
}


BT::NodeStatus CheckBattery()
{
    std::cout << "[ Battery: OK ]" << std::endl;
    return BT::NodeStatus::SUCCESS;
}


NodeStatus GripperInterface::open()
{
    _open = true;
    std::cout << "GripperInterface::open" << std::endl;
    return NodeStatus::SUCCESS;
}

NodeStatus GripperInterface::close()
{
    std::cout << "GripperInterface::close" << std::endl;
    _open = false;
    return NodeStatus::SUCCESS;
}
