#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Link
{
    public:
        vector<Node> connected_nodes;
        bool isUniDirectional = true;
        
        Link() {}

        void addNode(Node node)
        {
            connected_nodes.push_back(node);
        }

        void sendToLink(Node node)
        {
        	vector<Node>::iterator ptr;

           	for (ptr = connected_nodes.begin(); ptr < connected_nodes.end(); ptr++)
                ptr.receive(frame);
        }
};
