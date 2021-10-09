#include <iostream>
#include "Node.h"

using namespace std;

void test1()
{
	Link link;

	uint64_t node_mac_addr1[6] = {0x00, 0x0D, 0x3F, 0xCD, 0x02, 0x5F};
    Node node1(node_mac_addr1);

    uint64_t node_mac_addr2[6] = {0x01, 0x0C, 0x3E, 0xC5, 0x03, 0x5D};
    Node node2(node_mac_addr2);

    uint64_t node_mac_addr3[6] = {0x01, 0x0B, 0x5C, 0xC5, 0x03, 0x5D};
    Node node3(node_mac_addr3);

    uint64_t broadcast_mac_addr3[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    link.connected_nodes.push_back(&node1);
    node1.connected_links.push_back(&link);

    link.connected_nodes.push_back(&node2);
    node2.connected_links.push_back(&link);

    link.connected_nodes.push_back(&node3);
    node3.connected_links.push_back(&link);

    cout << "Unicast message examples:\n" << endl;
    node1.transmit(node_mac_addr2); // Node 1 --> Node 2
    node2.transmit(node_mac_addr1); // Node 2 --> Node 1
    node2.transmit(node_mac_addr3); // Node 2 --> Node 3

    cout << "\nBroadcast message examples:\n" << endl;
    node1.transmit(broadcast_mac_addr3); // Broadcast from Node 1
    node3.transmit(broadcast_mac_addr3); // Broadcast from Node 3
}

int main()
{   
	test1();
    return 0;
}