#include <iostream>
#include <vector>
using namespace std;

class Link
{
    public:
        vector<Node> connected_nodes;
        bool isUniDirectional = true;
        
        void addNodes(Node node)
        {
            connected_nodes.push_back(node);
        }
};
