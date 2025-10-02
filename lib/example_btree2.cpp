//
// Created by damiano on 28/09/25.
//

#include "example_btree2.h"


// ########################################################
// ###    TREE                                          ###
// ########################################################
void MainTree::register_tree(BT::BehaviorTreeFactory *factory) {
    factory->registerNodeType<SaySomething>("SaySomething");
    factory->registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");
    factory->registerNodeType<ThinkWhatToSay2>("ThinkWhatToSay2");
}





// ########################################################
// ###    METHODS                                       ###
// ########################################################
BT::NodeStatus SaySomething::tick()
{
    // std::string msg;
    // getInput("message", msg);
    BT::Expected<std::string> msg = getInput<std::string>("message");

    // Check if expected is valid. If not, throw its error
    if (!msg)
    {
        throw BT::RuntimeError("missing required input [message]: ", msg.error() );
    }

    // use the method value() to extract the valid message.
    std::cout << "Robot says: " << msg.value() << std::endl;
    return BT::NodeStatus::SUCCESS;
}


BT::PortsList SaySomething::providedPorts()
{
    return {BT::InputPort<std::string>("message")};
}






BT::NodeStatus ThinkWhatToSay::tick()
{
    setOutput("text", "The answer is 42");
    return BT::NodeStatus::SUCCESS;
}

BT::PortsList ThinkWhatToSay::providedPorts()
{
    return {BT::OutputPort<std::string>("text")};
}






BT::NodeStatus ThinkWhatToSay2::tick()
{
    setOutput("text", "Hola");
    return BT::NodeStatus::SUCCESS;
}

BT::PortsList ThinkWhatToSay2::providedPorts()
{
    return {BT::OutputPort<std::string>("text")};
}