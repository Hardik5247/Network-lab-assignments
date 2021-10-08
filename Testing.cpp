#include <iostream>
#include "Link.h"
#include "Node.h"
#include "DataFrame.h"

using namespace std;

void test1()
{
	Link link();

	uint64_t node_mac_addr1[6] = {0x00, 0x0d, 0x3f, 0xcd, 0x02, 0x5f};
    Node node1(node_mac_addr1);

    uint64_t node_mac_addr2[6] = {0x01, 0x0c, 0x3e, 0xc5, 0x01, 0x5d};
    Node node2(node_mac_addr2);

    node1.addLink(link);
    link.addNode(node1);
    
    node2.addLink(link);
    link.addNode(node2);

    node1.transmit(node_mac_addr2);
}

int main()
{   
	test1();
    return 0;
}