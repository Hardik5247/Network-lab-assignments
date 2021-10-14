#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include "DataFrame.h"

using namespace std;

class Link;

static int count2 = 0;

/** 
 * Node Class 
 **/
class Node
{
    private:
        int device_id;
        uint64_t mac_addr[6];
        int count;
    public:
        vector<Link*> connected_links;

        Node(uint64_t b[])
        {
            device_id = (++count2);
            count = 0;
            for(int i = 0; i < 5; ++i)
                mac_addr[i] = b[i];
            
        }
        
        void receive(DataFrame frame);

        template <size_t n>
        void transmit(uint64_t (&dest_mac_addr)[n]);
};

/** 
 * Link Class 
 **/
class Link
{
    public:
        bool isUniDirectional = true;

    public:
        vector<Node*> connected_nodes;

        void sendToLink(DataFrame frame);
};

/** 
 * Node receive function for unicast and broadcast messages 
 **/
void Node::receive(DataFrame frame)
{   
    string empty_str("");
    string str(frame.ReadMessage(mac_addr));

    if (str.compare(empty_str) == 0)
        return;
    cout << "Data received by node " << device_id << " is '" << 
            str << "'" << endl;
}

/** 
 * Link function which ensures frames
 * are flying around in the bus network 
 **/
void Link::sendToLink(DataFrame frame)
{   
    vector<Node*>::iterator ptr;
    
    for (ptr = connected_nodes.begin(); ptr < connected_nodes.end(); ptr++)
        (**ptr).receive(frame);
}

/** 
 * Node transmit function for unicast and broadcast messages 
 **/
template <size_t n>
void Node::transmit(uint64_t (&dest_mac_addr)[n])
{  
    if (n != 6)    
        return;
    
    string str("Greetings from node " + to_string(device_id));

    DataFrame frame(str, mac_addr, dest_mac_addr, count);
    
    cout << "Data sent by node " << device_id << " is '" << str << "'" << endl;

    vector<Link*>::iterator ptr;

    for (ptr = connected_links.begin(); ptr < connected_links.end(); ptr++)
        (**ptr).sendToLink(frame);
}
