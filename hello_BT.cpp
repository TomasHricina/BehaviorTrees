
#include "behaviortree_cpp_v3/bt_factory.h"
#include "dummy_nodes.h"

int main()
{
    BehaviorTreeFactory factory;
    using namespace DummyNodes;
    factory.registerNodeType<ApproachObject>("ApproachObject");
    auto tree = factory.createTreeFromFile("./my_tree.xml");
    tree.tickRoot();
    return 0;
}
