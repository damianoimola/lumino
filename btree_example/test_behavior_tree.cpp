#include "behaviortree_cpp/bt_factory.h"

using namespace BT;

static const char* xml_text = R"(
 <root BTCPP_format="4" >

     <BehaviorTree ID="MainTree">
        <Sequence name="root">
            <AlwaysSuccess/>
            <SaySomething   message="this works too" />
            <ThinkWhatToSay text="{the_answer}"/>
            <ThinkWhatToSay2 text="{the_answer2}"/>
            <SaySomething   message="{the_answer2}" />
            <SaySomething   message="{the_answer}" />
        </Sequence>
     </BehaviorTree>

 </root>
 )";





class SaySomething : public BT::SyncActionNode
{
public:
    SaySomething(const std::string& name, const BT::NodeConfig& config) :
          BT::SyncActionNode(name, config)
    {}

    BT::NodeStatus tick() override
    {
        std::string msg;
        getInput("message", msg);
        std::cout << msg << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    static BT::PortsList providedPorts()
    {
        return {BT::InputPort<std::string>("message")};
    }
};



class ThinkWhatToSay : public BT::SyncActionNode
{
public:
    ThinkWhatToSay(const std::string& name, const BT::NodeConfig& config) :
          BT::SyncActionNode(name, config)
    {}

    BT::NodeStatus tick() override
    {
        setOutput("text", "The answer is 42");
        return BT::NodeStatus::SUCCESS;
    }

    static BT::PortsList providedPorts()
    {
        return {BT::OutputPort<std::string>("text")};
    }
};


class ThinkWhatToSay2 : public BT::SyncActionNode
{
public:
    ThinkWhatToSay2(const std::string& name, const BT::NodeConfig& config) :
          BT::SyncActionNode(name, config)
    {}

    BT::NodeStatus tick() override
    {
        setOutput("text", "Hola");
        return BT::NodeStatus::SUCCESS;
    }

    static BT::PortsList providedPorts()
    {
        return {BT::OutputPort<std::string>("text")};
    }
};


// int main()
// {
//
//     BehaviorTreeFactory factory;
//
//     factory.registerNodeType<SaySomething>("SaySomething");
//     factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");
//     factory.registerNodeType<ThinkWhatToSay2>("ThinkWhatToSay2");
//
//     auto tree = factory.createTreeFromText(xml_text);
//
//     tree.tickWhileRunning();
//
//     return 0;
// }