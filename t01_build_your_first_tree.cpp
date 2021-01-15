#include "behaviortree_cpp_v3/bt_factory.h"
#include "dummy_nodes.h"

class ApproachObject : public BT::SyncActionNode
{
  public:
    ApproachObject(const std::string& name) :
        BT::SyncActionNode(name, {})
    {
    }

    BT::NodeStatus tick() override
    {
        std::cout << "ApproachObject: " << this->name() << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};


int main()
{
    
    BehaviorTreeFactory factory;  
    //with no BT::, it produces this error:
    //with no BT:: 
    // error: ‘BehaviorTreeFactory’ was not declared in this scope; did you mean ‘BT::BehaviorTreeFactory’?
    //  |     BehaviorTreeFactory factory;
    //  |     ^~~~~~~~~~~~~~~~~~~
    //  |     BT::BehaviorTreeFactory
  
    //with BT::BehaviorTreeFactory factory;
    //t01_build_your_first_tree.cpp:26:13: error: parse error in template argument list
    //  |     factory.registerNodeType<ApproachObject>("ApproachObject");
    //  |             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    using namespace DummyNodes;

    factory.registerNodeType<ApproachObject>("ApproachObject");

    auto tree = factory.createTreeFromFile("./my_tree.xml");

    tree.tickRoot();

    return 0;
}
