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

    using namespace DummyNodes;

    factory.registerNodeType<ApproachObject>("ApproachObject");

    auto tree = factory.createTreeFromFile("./my_tree.xml");

    tree.tickRoot();

    return 0;
}
